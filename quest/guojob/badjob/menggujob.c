#include <ansi.h>

mixed names = ({
        ({
        "��ȸ����","��������","�׻�����","��������",
        }),
        ({
         "�α�","��å","ƫ��","����","С��","�к�","��ܽ","������",
         "С��","����ϰ�","����ͨ","�","����","������","��С��","�α�",
	 "��һ��","��ܽ","����","���","ʷ����","ʷ��ǿ","ʷ�Ͻ�","ʷ���",
	 "ʷ����","�����","������","Ү����","��Ӣ",
        }),
        });

string ask_job()
{ 
  object  ob, me,newob;
  int exp,position;
  string target,myfam,obfam,job_type;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
  if (interactive(ob) && ob->query_temp("menggu_job_target")
      && (int)ob->query_condition("menggu_mission"))  
       return "����һ�ε�����û���!";
  if (interactive(ob) && !ob->query_temp("menggu_job_target")
      && (int)ob->query_condition("menggu_mission"))  
       return "����²������ȵȻ�ɡ�";
   
    if (interactive(ob) &&
       (int)ob->query_condition("menggu_busy"))  
       return "�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";

if (ob->query_skill("force",1)<100)
       return "�ҿ�����书����������\n";

if (ob->query("shen")>0)
       return "�ҿ��㵽����һ����ϸ��\n";
	
	if(exp<=100000)     
    return "����书̫����,����ǿ�������ɡ�\n";
    job_type="��ɱ";
   	ob->set_temp("menggu_job_type",job_type);
        
	if(job_type=="��ɱ")
	{target = names[1][random(sizeof(names[1]))];
        ob->apply_condition("menggu_mission",30);    
	ob->set_temp("menggu_job_target", target);
	ob->set_temp("mgjob", 1);
        newob = new(__DIR__"ling");
        newob->set("long", "
        ��ɱ��
" + target + "������
        ��Ԫ\n");
        newob->move(ob);

    message_vision(HIW"$N����$n˵��:����Ϣ����������ʿ����Ԯ����,������Ҫ��"+target+"������������"+target+"һ��ɵ�!\n"NOR , me,ob);
     if( (string)this_player()->query("family/family_name")=="������" ) 
{     
        newob = new(__DIR__"item1");
        newob->move(ob);
    message_vision(HIW"$N����$n˵������˵�����̶���ʯ�ҶԵ����ĵ£����ʯ�ҷ۾͸�����!\n"NOR , me,ob);
}
     if( (string)this_player()->query("family/family_name")=="������" ) 
{     
        newob = new(__DIR__"item2");
        newob->move(ob);
    message_vision(HIW"$N����$n˵������˵�����ɶ����ɺ�ҩ�Ե����ĵ£�����ɺ�ҩ�͸�����!\n"NOR , me,ob);
}
     if( (string)this_player()->query("family/family_name")=="ѩɽ��" ) 
{     
        newob = new(__DIR__"item3");
        newob->move(ob);
    message_vision(HIW"$N����$n˵������˵ѩɽ�¶��������ͺ�ɢ�Ե����ĵ£���������ͺ�ɢ�͸�����!\n"NOR , me,ob);
}

	return "���ʧ���ˣ���Ҫ�����!";
	}
}


string ask_fangqi()
{
         object me;
         me = this_player();
         if(me->query_condition("menggu_mission")<=1)
         return "��û��������,������Ϲ����ʲ��?";
         me->clear_condition("menggu_mission");
me->apply_condition("menggu_busy",8);    
destruct(present("hehe san",me));
destruct(present("meng hanyao",me));
destruct(present("shi huifeng",me));
me->clear_condition("menggu_mission");
me->delete_temp("menggu_job_target");
me->delete_temp("menggu_job_type");
me->delete_temp("mgjob");
		 me->delete_temp("menggu_job_type");
         return "�´β�����ʧ��!! ��";
}

int accept_object(object who, object ob,object me)
{
        if ( ob->query("id") != "corpse") {
                command("say ������������?");
                return 0;
        }
        if ( !who->query_temp("menggu_job_target") ) {
                command("say �ð��������������������");
                return 0;
        }

        if( who->query_temp("mgjob")!=3){
                command("say ��û�а�������ʿ�ɵ�����Ҫ��?");
                return 0;
        }

        if( who->query_temp("menggu_job_type")=="����")
		if (ob->query_temp("must_killby")!= who->query("id")
			||ob->query("victim_user") )
		{       command("shake");
                command("say ��ɱ�����ˡ�");
                return 0;
        } 
command("say ���ĺ�!!Ϊ���Ǵ����˴󹦡�");
who->add("combat_exp",220+random(100));
who->add("shen",-50);
who->add("potential",150+random(100));
who->clear_condition("menggu_mission");
who->delete_temp("menggu_job_target");
who->delete_temp("menggu_job_type");
who->delete_temp("mgjob");
destruct(present("hehe san",who));
destruct(present("meng hanyao",who));
destruct(present("shi huifeng",who));
call_out("destroying", 1, ob);
        return 1;
}



void destroying(object ob)
{
        destruct(ob);
        return;
}