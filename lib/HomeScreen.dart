import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
class HomeScreen extends StatefulWidget {
  const HomeScreen({Key? key}) : super(key: key);

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  final dbref = FirebaseDatabase.instance.ref() ;
 bool checkOk = false ;


  @override
  Widget build(BuildContext context) {
    double height = MediaQuery.of(context).size.height - kToolbarHeight;
    double width = MediaQuery.of(context).size.width;
    return SafeArea(
      child: Scaffold(
        body: Column(
          children: [
            Padding(
              padding: EdgeInsets.all(8.0),
              child: Container(
                height: height * 0.6,
                width: width,
                child: Image.asset('assets/bulb.png'),
              ),
            ),
            InkWell(
              onTap: ()async{

                if(checkOk ==  false){
               await   dbref.set({
                    'light':0
                  });
                  setState(() {
                    checkOk = true;
                  });
                }else{
                  await   dbref.set({
                    'light':1
                  });
                  setState(() {
                    checkOk = false;
                  });
                }

              },
              child: Container(
                height: height * 0.15,
                width: width,
                decoration: BoxDecoration(
                    color: Colors.brown,
                    borderRadius:
                        BorderRadius.all(Radius.circular(height * 0.05))),
                child: Center(
                    child: Text(
                  'Switch',
                  style: TextStyle(fontSize: height * 0.04, color: Colors.white),
                )),
              ),
            )
          ],
        ),
      ),
    );
  }
}
