#include <ansi.h>
int ckiller=3;
mixed names = ({
        ({
        "����ǰ��","���������","���̶����","���̴��","���̴��",
        "��΢��","��΢��","������","�һ������","�һ������",
        "�һ������","�һ����Ʒ�","��ľ�����","��������","����ɽ��",                
//"����ɽ��",
        }),
        });

string ask_jianxi()
{
     object guo,ob;
     string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "����")
	  return "������ɵ���!!";//guo busy time 
	  
	  if (ob->query_condition("mjtjob2"))
	  return "����û���������!";//guo busy time 

//	  if (guo->query_condition("mingjiaojob"))
//	  return "��û���յ��κ���Ϣ��";//guo busy time 
	  
     if(ob->query("combat_exp")<100000)
      return  "��Ĺ���̫���ˡ�";//too low exp

      if( ob->query_skill("jiuyang-shengong",1) < 50)
      return  "��ı����ڹ�̫���ˡ�";//too low exp      
	  where=names[0][random(15)];
//	  guo->apply_condition("mingjiaojob",16);
	  ob->set("mjjob",1);
	  ob->apply_condition("mingjiaojob",60);
          ckiller=3;
ob->set_temp("mjtjob",where);ob->apply_condition("mjtjob",24);ob->apply_condition("mjtjob2",16);
//      call_out("job",80,ob,where,);
	  return    "�Ҹյõ���Ϣ����һ��������ɵ�������˵���ǰ������ʥ�̡�\n"+
		        "          ��Ͽ�ȥ"+where+"�����أ�\n"+
			    "          ���������˵����죬���С�ġ�"; 

}

void job(object ob,string where,int maxpot)
{    object obj,gift;
      object guo=this_object();     
     int i=0;
if(!ob) return;
if(environment(ob)->query("short")!=where && ob->query_condition("mingjiaojob"))
{
             tell_object(ob, HIY "\n����صĵط����԰�!��������ɱ�������̣�������ʧ�ܣ�\n" NOR); 
}
     guo->apply_condition("mingjiaojob",0);
     if(environment(ob)->query("short")==where&&ob->query_condition("mingjiaojob"))
	 {
	    if (ckiller>0)
	    {if (random(20)>15)
			{ obj=new(__DIR__"wudang");   
	          obj->do_copy(ob,maxpot,3);
	          obj->set("title",HIY"�䵱�ɵ���"NOR);     
              obj->move(environment(ob));
              obj->kill_ob(ob);
			}
		     else 
			{
	  	      obj=new(__DIR__"emei"); 
		      obj->do_copy(ob,maxpot,1);
	          obj->set("title",HIG"�����ɵ���"NOR);
	          obj->move(environment(ob));
              obj->kill_ob(ob);
	          obj=new(__DIR__"shaolin");
	           obj->set("title",HIW"�����ɵ���"NOR);
		      if (random(20)>5)
			  {obj->do_copy(ob,maxpot,2);
	           obj->set("title",HIW"�����ɵ���"NOR);
			  }
			   else 
               obj->do_copy(ob,maxpot,1);
		       obj->move(environment(ob));
               obj->kill_ob(ob);
			 }  
                  ckiller=ckiller-1;
	  	  call_out("job",60,ob,where,maxpot,ckiller-1);
	    }
	    else 
		 {if (present("menggu",environment(ob)))
			{//present menggu dahan,then mission failed
			 tell_room(environment(ob),HIC"�ɹű��ӻ��֣������������ߡ�\n��������Ҵ�ææ���뿪�ˡ�\n"NOR);
             tell_object(ob, HIY "\n��������ɱ�������̣�������ʧ�ܣ�\n" NOR); 
			}
 	     else{
				obj=new(__DIR__"jianxi"); 
				obj->do_copy(ob,maxpot);
				obj->set("title",HIG"��������"NOR);
                                obj->set_temp("hostmj",ob->query("id"));
				obj->move(environment(ob));
				message_vision(HIY"$N��Ц���ѣ���ƾ���Ǽ���Ҳ�뵲ס�ҵ�ȥ·?\n"NOR, obj);
				obj->kill_ob(ob);
     guo->apply_condition("mingjiaojob",0);
//				gift=new(__DIR__"mijian");
//			��	gift->set_temp("host",ob->query("id"));
//				gift->move(obj);
				}
		}
	 }
}