i=int(input('enter a year'))
if (i%4)==0:
  if (i%100)==0:
    if (i%400)==0:
      print('leap year')
    else:
      print('not a lep year')
  else:
     print('not a lep year')
else:
  print('not a lep year')
