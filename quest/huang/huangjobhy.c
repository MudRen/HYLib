#include "where.h"


string ask_job()
{ 
  object  ob, me,gift,*team,obj;
  int exp,position,i;
  mapping target;
  string str;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
  if (interactive(ob) && (int)ob->query_condition("huang_mission"))  
       return "����һ�ε�����û���!";
  if (interactive(ob) && (int)ob->query_condition("huang_busy"))  
       return "�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";
  if (interactive(ob) && (int)ob->query_condition("guojob2_busy"))  
       return "�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";
       if ((int)ob->query_condition("gf_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("feitian2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("gf_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("gumu_job"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("hu_song"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("huang_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("huaxunshan"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("husong_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("hxsd_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("lingjiu_song"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("lingxiao2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("ljjob2"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("lyjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("lyjob2"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("menggu_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("mingjiaojob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("mr_job"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("nonamejob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("quanzhenjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("riyue_guard"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("riyuejob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("roomjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("ry2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("shaolin_song"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("taohuajob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("tz_job"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("wdj2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("xsjob2"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("xsjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("xh_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("wudangjob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("bt2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("dali_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("emeijob"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("menpai_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("yl2_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("zzz_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
       if ((int)ob->query_condition("yue_busy"))  
       return "�ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";


	if(exp<=100000)     
    return "����书̫����,����ǿ�������ɡ�\n";
    
	target = wheres[random(sizeof(wheres))];
    for(i=100;i*i*i/10<=exp;i++);//i=maxpot
	//obj=new(__DIR__"killer1");
	if(random(10)>7)
	{obj=new(__DIR__"skiller"+sprintf("%d",random(3)+1));
	 i=i+10+random(10);
	 obj->do_copy(ob,i);
	 obj->set("title",HIR"����һ��"NOR);
	 ob->set_temp("huang_job_super",1);
	}
	else
	{ obj=new(__DIR__"killer");
	  i=i-random(10);
	  obj->do_copy(ob,i);
	}
	obj->move(target["weizhi"]);
	obj->set_temp("must_killby",ob->query("id")); 
    ob->set_temp("huang_job_target", target["chinese"]);//where
    ob->apply_condition("huang_mission",30);
    ob->apply_condition("menpai_busy",13);
    ob->start_busy(2);
	command("nod");
	str="����ָ��������ڡ�"+target["chinese"]+"��һ����������";
	command("say "+str);
    return "��ȥѲ��һ�¡�";
	
}

int accept_object(object who, object ob,object me)
{
        if ( ob->query("id") != "corpse") {
                command("say ������������?");
                return 0;
        }
        if ( !who->query_temp("huang_job_target") ) {
                command("say �ð��������������������");
                return 0;
        }
	       	if (ob->query_temp("must_killby")!= who->query("id")
			||ob->query("victim_user")||who->query_temp("huang_given") )
		{       command("shake");
                command("say ��ɱ�����ˡ�");
                return 0;
        } 

  /*      if ( ob->query("kill_by") != who) {
                command("say ��������ƺ��������Լ���ɵİɣ�");
                return 0;
        }
*/      who->set_temp("huang_given",1);
        call_out("destroying", 1, ob);
        call_out("ok", 1, who);
        return 1;
}

void ok(object who)
{
        int exp,pot,count,i;
        if (!who) return;
        command("pat" + who->query("id"));
        command("say ���ĺã����͸�!");
        if(!who->query("huang_job_count"))
		who->set("huang_job_count",1);
        else
		who->add("huang_job_count",1);        
		count=who->query("huang_job_count");
		for(i=0;i*i<count;i++);
		exp=200+random(20)+i*2;
        if(who->query_temp("huang_job_super"))
        {exp+=100;
		 who->delete_temp("huang_job_super");
		}
		pot=exp/2+random(10);
		who->add("potential",pot);
        who->add("combat_exp",exp);
        who->clear_condition("huang_mission");
		who->delete_temp("huang_job_target");
        who->delete_temp("huang_given");
		who->apply_condition("huang_busy",3+random(4));
        tell_object(who,HIW"�㱻�����ˣ�\n" + 
        chinese_number(exp) + "��ʵս����\n" +
        chinese_number(pot) + "��Ǳ��\n"+
        NOR);
        return;
}


void destroying(object obj)
{
        destruct(obj);
        return;
}

string ask_fangqi()
{
         object me;
         me = this_player();
         if(!me->query_temp("huang_job_target"))
         return "��û��������,������Ϲ����ʲ��?";
         me->add("combat_exp",-80+random(20));
         me->apply_condition("huang_mission",6);
         me->delete_temp("huang_job_target");
	     return "û��ϵ,�´μ���Ŭ�� ��";
}

string ask_gonglao(object who)
{
  object me;
  int i;
           
  me = this_player();
  if(!me->query("huang_job_count"))
  i=0;
  else 
  i =(int)me->query("huang_job_count"); 
  message_vision(CYN"$N��$n˵��:���Ѿ������" + chinese_number(i) + "������\n"NOR,who,me);
  return "����Ŭ���ɣ�";
}
