[TOC]

## pickle file
- import pickle
- save pickle file

```
with open('filename.pickle','wb') as f:
   pickle.dump(python_object,f)
```

- load pickle file
```
with open('filename.pickle','wb') as f:
   python_object=pickle.load(f)
```


- verson compatibility
    - new version is compatible to older version, however, the older version cannot

## other language
- json file
    - import json
    - most native types can mapped, 
        - however, bytes and tuple are not
        - customize the serializer
            - json.dump(filename.json,f,default=customize_serializer.function)
            - json.load(f,object_hook=customize_serializer.fromjson)
