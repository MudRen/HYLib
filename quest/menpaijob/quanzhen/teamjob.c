#include <ansi.h>
int ckiller=3;
mixed names = ({
        ({
        "�Խ���","�̱�","������","���湬","����̨",
        "������","������","������","�ڷﶴ","���ԭ",
        "ȫ��̴���","������","��ɽͤ","����̶","������",                
        }),
        });

string ask_jianxi()
{
     object guo,ob;
     string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "ȫ���")
	  return "������ɵ���!!";//guo busy time 
	  
	  if (ob->query_condition("qztjob2"))
	  return "����û���������";//guo busy time 

//	  if (guo->query_condition("quanzhenjob"))
//	  return "��û���յ��κ���Ϣ��";//guo busy time 
	  
     if(ob->query("combat_exp")<100000)
      return  "��Ĺ���̫���ˡ�";//too low exp
      if( ob->query_skill("xiantian-qigong",1) < 50)
      return  "��ı����ڹ�̫���ˡ�";//too low exp

      
	  where=names[0][random(15)];
//	  guo->apply_condition("quanzhenjob",16);
	  ob->set("qzjob",1);
	  ob->apply_condition("quanzhenjob",60);
          ckiller=3;
ob->set_temp("qztjob",where);ob->apply_condition("qztjob",22);ob->apply_condition("qztjob2",15);
//      call_out("job",80,ob,where,);
	  return    "�Ҹյõ���Ϣ�����ɹŻ�����������һȺ�ɹű�ǰ��,���ҽ̲�����\n"+
		        "          ��Ͽ�ȥ"+where+"�����أ�\n"+
			    "          ���������˵Ļ������������С�ġ�"; 

}

void job(object ob,string where,int maxpot)
{    object obj,gift;
     object guo=this_object();
     int i=0;
if(!ob) return;

if(environment(ob)->query("short")!=where && ob->query_condition("quanzhenjob"))
{
             tell_object(ob, HIY "\n����صĵط����԰�!�ɹŻ��̷�������ȫ����ˣ�������ʧ�ܣ�\n" NOR); 
}

     guo->apply_condition("quanzhenjob",0);
     if(environment(ob)->query("short")==where&&ob->query_condition("quanzhenjob"))
	 {
	    if (ckiller>0)
	    {if (random(20)>15)
			{ obj=new(__DIR__"mengu3");   
	          obj->do_copy(ob,maxpot,3);
	          obj->set("title",HIY"�ɹű�"NOR);     
              obj->move(environment(ob));
              obj->kill_ob(ob);
			}
		     else 
			{
	  	      obj=new(__DIR__"mengu3"); 
		      obj->do_copy(ob,maxpot,1);
	          obj->set("title",HIG"�ɹű�"NOR);
	          obj->move(environment(ob));
              obj->kill_ob(ob);
	          obj=new(__DIR__"mengu3");
	           obj->set("title",HIW"�ɹű�"NOR);
		      if (random(20)>5)
			  {obj->do_copy(ob,maxpot,2);
	           obj->set("title",HIW"�ɹű�"NOR);
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
			 tell_room(environment(ob),HIC"�ɹű��ӻ��֣�ʾ���ɹŻ��̷������ߡ�\n�ɹŻ��̷����Ҵ�ææ���뿪�ˡ�\n"NOR);
             tell_object(ob, HIY "\n�ɹŻ��̷�������ȫ����ˣ�������ʧ�ܣ�\n" NOR); 
//                                guo->apply_condition("quanzhenjob",0);
			}
 	     else{
				obj=new(__DIR__"jianxi"); 
				obj->do_copy(ob,maxpot);
				obj->set("title",HIG"�ɹŻ��̷���"NOR);
				obj->move(environment(ob));
                                obj->set_temp("host",ob->query("id"));
				message_vision(HIY"$N��Ц���ѣ������ܴ󺺵ķ��,��Ȼȫ������������!!\n"NOR, obj);
				obj->kill_ob(ob);
                                guo->apply_condition("quanzhenjob",0);
				}
		}
	 }
}