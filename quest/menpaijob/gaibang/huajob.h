#include <ansi.h>
int ask_job()
{
        object me;
        object ob;
int exp,pot;
          mapping myfam;

        me=this_player();
        myfam=(mapping)me->query("family");
        

        if (  !myfam || myfam["family_name"]!="ؤ��"  )
        {
                command("say ���뱾�ɺ��޹�ϵ�������²�����������");
                return 1;
        }
        

        if ( (int)me->query("combat_exp")<80000 )
        {
                command("say ��Ĺ����У���Ҫ��ѧ�㹦��");
                return 1;
        }
      if( (int)me->query_skill("huntian-qigong",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("³���϶���$Nҡ��ҡͷ˵����Ȼ�����!\n", me);
                      return 1;
            }
        if ( me->query_temp("xhjob_failed") )
        {
                command("poor "+me->query("id"));
                command("say �㻹������������ɣ�����ְѹ��������ˡ�");
                        me->delete_temp("xhjob_start");
                        me->delete_temp("xhjob_failed");
                return 1;
        }
        
        if ( me->query_temp("xhjob_start") && !(me->query_temp("xhjob_ok")) )
        {
                command("hmm");
                command("say ���Ѿ��й����ˡ�������ȥ����");
                return 1;
        }
        
        if (me->query_temp("xhjob_ok") ==1 )
        {
              if (random(10)==0)
              this_object()->set("book_count", 1);
                command("say �úã��ɵĺã�����ȥЪЪ�ɡ�");
               if (me->query("combat_exp")<800000)
               {
               me->add("combat_exp", random(100) + 80);
               me->add("potential", random(100) + 80);
               }

exp=380+random(400);
pot=280+random(300);
                me->add("combat_exp",exp);
                me->add("potential",pot);
   tell_object(me, "�㱻������"+chinese_number(exp)+"�㾭��ֵ��\n"+chinese_number(pot)+"��Ǳ��\n");
                me->delete_temp("xhjob_start");
                me->add("kill",20);
                me->delete_temp("xhjob_ok");
                return 1;
        }

        if (me->query_condition("xh_busy"))
        {
                command("say ������Ϣһ�ᣬ�Ȼ�������");
                return 1;
        }
        
        command("say ���������ã���˵�����ڹؿ������������ˣ���ȥ�������");
        command("say ע�⣬�����ɹű������ˡ�");
        command("say ������һ����֮�ڸϵ�����ȥ��");
        
        me->set_temp("xhjob_ok",0);
        me->set_temp("xhjob_start",1);
        me->set_temp("where",__DIR__"guanka");
        
        call_out("do_goto", 60, me);

        return 1;
}

void do_goto(object me)
{
        object where;

        where = environment(me);

        if (file_name(where)==me->query_temp("where"))
        {
                if (!(me->query_temp("shouwei")))  {
                tell_object(me,HIC"��Ӧ�ÿ�ʼ����(shouwei)�ˡ�\n"NOR);
                }
                return;
        }
        else
        {
                tell_object(me,"\n����Ȼû����һ����֮�ڸϵ�Ŀ�ĵأ�����ʧ�ܡ�\n");
                me->set_temp("xhjob_failed",1);
                me->apply_condition("zzz_busy",6);
        }
        return;
}

