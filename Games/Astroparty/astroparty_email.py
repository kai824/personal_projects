#download and run astroparty

import imaplib
import os
import email

class EmailWrapper:
    hostname = None     # herp
    username = None     # derp
    password = None     # might encrypt this if there is time

    def __init__(self, host, user, passwd):
        self.hostname = host
        self.username = user 
        self.password = passwd

    # Create connection and return it
    def connect(self, verbose=True):
        print('Downloading scripts...')
        if verbose: print('Connecting to ', self.hostname)
        connection = imaplib.IMAP4_SSL(self.hostname)
        if verbose: print ('Logging in')
        connection.login(self.username, self.password)
        connection.select('Inbox')
        return connection

    # Grab last email in inbox and return it from connection
    def get_last_email(self, c):
        # Get list of emails
        result, data = c.search(None, "ALL")

        # get last ID
        ids = data[0]  
        idList = ids.split()
        last=1
        while True:
            lastEmailID = idList[-last]

            # Fetch email
            result, data = c.fetch(lastEmailID, "(RFC822)")

            # Seclect body and return it
            rawEmail = data[0][1]
            
            emailMessage = email.message_from_string(rawEmail.decode('utf-8'))
            #if emailMessage['Subject'][:5]=='Astro' and \
 #              emailMessage['From'] in ['astroparty.sg@gmail.com','Astroparty Code <astroparty.sg@gmail.com>']:
            if emailMessage['Subject']=='Code for astro' and \
               emailMessage['From'] in ['astroparty.sg@gmail.com','Astroparty Code <astroparty.sg@gmail.com>',\
                                        'yikai.tan.sg@gmail.com','Yi Kai Tan <yikai.tan.sg@gmail.com>']:
                break
            last+=1
        return emailMessage


    def close_connection(self, c):
        c.close()
        c.logout()

e=EmailWrapper('imap.gmail.com','astroparty.sg@gmail.com','Berrrrr5')
mail=e.connect()
a=e.get_last_email(mail)
#a.get_payload()[0].get_payload()#for email content as a string...
e.close_connection(mail)
for part in a.walk():
        # this part comes from the snipped I don't understand yet... 
        if part.get_content_maintype() == 'multipart':
            continue
        if part.get('Content-Disposition') is None:
            continue
        fileName = part.get_filename()
        exec(part.get_payload(decode=True).decode())
