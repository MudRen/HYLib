

#include <ansi.h>

inherit NPC;

string ask_for_yao();
string ask_for_present();

void create()
{
    set_name("��������", ({ "liwu man", "man" }) );
	set("title", HIY"����"+HIW" ʹ��"NOR);
	set("gender", "����" );

	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
         
	set("long",
		"�ף��������������ô��ʥ�������ŵ�һģһ�����Ǻ�...\n"
                "���������﷢������������������Ҫ��(ask men about ���)\n" );

	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set("inquiry", ([
		"����"   : (: ask_for_yao :),		
		"����"   : (: ask_for_present :),
	]) );

	set_temp("no_kill", 1);
	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
        set("jiali",300);

	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("force",500);
        set_skill("literate",500);
        set_skill("cuff", 500);

        set_skill("qiankundanuoyi",500);
        set_skill("jingang-quan",500);
        set_skill("hunyuan-yiqi",500);
     
        map_skill("force", "hunyuan-yiqi");
	map_skill("parry", "qiankundanuoyi");
	map_skill("cuff", "jingang-quan");
        map_skill("dodge", "qiankundanuoyi");
        
        prepare_skill("cuff", "jingang-quan");
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 200);


        set("chat_msg_combat", ({
		(: perform_action, "cuff.jingang" :),
		(: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                
	}) );


	setup();
        carry_object(__DIR__"yuyi")->wear();
	
	
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}


void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;

      command("say ������������İɣ�\n");
//      Ԫ��,������,�Ͷ���,�����,��ͯ��,������,������,�����
//      ���˽�,���˽�,ʥ����,����,Ԫ����,�����,�����,������,
}

string ask_for_present()
{ 
mapping *holiday= ({

	          ([
                      "name":             HIR"Ԫ��"NOR,
                      "year":             "either",
                      "month":            "Jan",
                      "day":              "01",
                  ]),
  
                  ([
                      "name":             HIW"������"NOR,
                      "year":             "either",
                      "month":            "Apr",
                      "day":              "05",
                  ]),

                  ([
                      "name":             HIR"�Ͷ���"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"�����"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "04",
                  ]),

                  ([
                      "name":             HIR"��ͯ��"NOR,
                      "year":             "either",
                      "month":            "Jun",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"������"NOR,
                      "year":             "either",
                      "month":            "Jul",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"������"NOR,
                      "year":             "either",
                      "month":            "Aug",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"�����"NOR,
                      "year":             "either",
                      "month":            "Oct",
                      "day":              "01",
                  ]),

       		  ([
                      "name":             HIR"���˽�"NOR,
                      "year":             "eihter",
                      "month":            "Feb",
                      "day":              "14",                    
                  ]),

                  ([
                      "name":             HIC"���˽�"NOR,
                      "year":             "either",
                      "month":            "Apr",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"ʥ����"NOR,
                      "year":             "either", 
                      "month":            "Dec",
                      "day":              "24",
                  ]),

                  ([
                      "name":             HIR"��"+HIC"��"NOR,
                      "year":             "2002",
                      "month":            "Feb",
                      "day":              "1",
                  ]),

                  ([
                      "name":             HIR"Ԫ��"NOR+"��",
                      "year":             "2008",
                      "month":            "Feb",
                      "day":              "23",
                  ]),
               
                  ([
                      "name":             HIR"����"NOR+"��",
                      "year":             "2008",
                      "month":            "Jun",
                      "day":              "22",
                  ]),
                      
       		  ([
                      "name":             HIY"����"NOR+"��",
                      "year":             "2008",
                      "month":            "Sep",
                      "day":              "14",                    
                  ]),

       		  ([
                      "name":             HIY"����"NOR+"��",
                      "year":             "2008",
                      "month":            "Oct",
                      "day":              "25",                    
                  ]),


       


                	
                  });
    object me,ob;
    mapping skl, today;
    string *sname;
    int i,how=0,what_day=100,neili,exp,pot;
    string week, month, year, day, time;
    string check;
    
    sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
   if(day=="")
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);



    for(i=0;i<sizeof(holiday);i++)
      {  today = holiday[i];
//         if(today["year"]!="either")
 if( month==today["month"]&&day==today["day"])
//year==today["year"]&&
               what_day=i;
            else if(month==today["month"]&&day==today["day"])
               what_day=i;
      }
    if(what_day==100)
{
    write("������:");
    write(month);
    write(day);
      return "���������ʲô����Ү��\n";
}    
    me = this_player();

    if ((int)me->query("combat_exp") <3000 || (int)me->query("mud_age")<18000)
        return "�ٺ٣������������ƭ�ң�û�ţ���\n";
      
    if ((int)me->query("combat_exp") >=3000 ) 
         {
		
	    skl = me->query_skills();
      if(skl) sname  = keys(skl);
            for(i=0; i<sizeof(skl); i++)
                   if (skl[sname[i]] >= 10)how=how+1; 
                          if(how<3)
                            return "�����ˮƽ����ȥ��һ�������\n";
	
          } 
     today = holiday[what_day];   

     check=year+today["name"];
     
     if(me->query("goodday_gift")==check)
       return "ÿ����һ�ݣ���Ҫ��ô̰�ĺò��ã�\n";
neili=280+random(888);
exp=68000+random(88888);
pot=18000+random(88888);
me->add("max_neili",neili);
me->add("combat_exp",exp);
me->add("potential",pot);
//     ob = new(__DIR__"red");
//     ob->move(me);
     me->set("goodday_gift",check);
     return today["name"]+"���֣�\n"+"�������˰�"+me->query("name")+"��"+HIR"������ǿ�����"NOR+"������"+neili+",����"+exp+",Ǳ��"+pot+"\n";
}

string ask_for_yao()
{ 
mapping *holiday= ({

	          ([
                      "name":             HIR"Ԫ��"NOR,
                      "year":             "either",
                      "month":            "Jan",
                      "day":              "01",
                  ]),
  
                  ([
                      "name":             HIW"������"NOR,
                      "year":             "either",
                      "month":            "Apr",
                      "day":              "05",
                  ]),

                  ([
                      "name":             HIR"�Ͷ���"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"�����"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "04",
                  ]),

                  ([
                      "name":             HIR"��ͯ��"NOR,
                      "year":             "either",
                      "month":            "Jun",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"������"NOR,
                      "year":             "either",
                      "month":            "Jul",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"������"NOR,
                      "year":             "either",
                      "month":            "Aug",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"�����"NOR,
                      "year":             "either",
                      "month":            "Oct",
                      "day":              "01",
                  ]),

       		  ([
                      "name":             HIR"���˽�"NOR,
                      "year":             "eihter",
                      "month":            "Feb",
                      "day":              "14",                    
                  ]),

                  ([
                      "name":             HIC"���˽�"NOR,
                      "year":             "either",
                      "month":            "Apr",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"ʥ����"NOR,
                      "year":             "either", 
                      "month":            "Dec",
                      "day":              "24",
                  ]),

                  ([
                      "name":             HIR"��"+HIC"��"NOR,
                      "year":             "2002",
                      "month":            "Feb",
                      "day":              "1",
                  ]),

                  ([
                      "name":             HIR"Ԫ��"NOR+"��",
                      "year":             "2008",
                      "month":            "Feb",
                      "day":              "23",
                  ]),
               
                  ([
                      "name":             HIR"����"NOR+"��",
                      "year":             "2008",
                      "month":            "Jun",
                      "day":              "22",
                  ]),
                      
       		  ([
                      "name":             HIY"����"NOR+"��",
                      "year":             "2008",
                      "month":            "Sep",
                      "day":              "14",                    
                  ]),

       		  ([
                      "name":             HIY"����"NOR+"��",
                      "year":             "2008",
                      "month":            "Oct",
                      "day":              "25",                    
                  ]),


       


                	
                  });
    object me,ob;
    mapping skl, today;
    string *sname;
    int i,how=0,what_day=100;
    string week, month, year, day, time;
    string check;
    
    sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
   if(day=="")
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);



    for(i=0;i<sizeof(holiday);i++)
      {  today = holiday[i];
//         if(today["year"]!="either")
 if(month==today["month"]&&day==today["day"])
//year==today["year"]&&
               what_day=i;
            else if(month==today["month"]&&day==today["day"])
               what_day=i;
      }
    me = this_player();
    
    if ((int)me->query("combat_exp") <3000 || (int)me->query("mud_age")<18000)
        return "�ٺ٣������������ƭ�ң�û�ţ���\n";

    if ((int)me->query("combat_exp") >=3000 ) 
         {
		
	    skl = me->query_skills();
      if(skl) sname  = keys(skl);
            for(i=0; i<sizeof(skl); i++)
                   if (skl[sname[i]] >= 10)how=how+1; 
                          if(how<3)
                            return "�����ˮƽ����ȥ��һ�������\n";
	
          } 

    if(what_day==100)
    {
     me->set("goodday_gift",0);
     return "������գ�\n";
    }
    write("������:");
    write(month);
    write(day);
      return "���첻�ṩ�������\n";
}

  
