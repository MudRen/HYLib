
void destroy(object me)
{
              destruct(me);
}

/*
void init()
{
        object ob;

        ::init();

        ob = this_player();
}
*/

void checking(object me,object ob)
{
        object room;
        object robber;
        room = environment(ob);        
          if (me->query("qi")<1)     {
                  if(ob->query_temp("start_job")==1)
                  {
                        ob->add_temp("killed_mgb",1);
                  }
                  else
                        ob->add_temp("help_killed",1);
              message_vision("$N���ڵ��������˼��£������������"HIR"��Ѫ"NOR"�����ˣ�\n",me);
                       remove_call_out("destroy");
                 call_out("destroy",1, me);
                  if(ob->query_condition("jobshadi_limit")==0)
                  {
                        message_vision(CYN"\nһ���س��α��ܹ���˵�����ɹ�������ʱ�������ˣ�$N���Ի�ȥ�����ˣ�\n"NOR,ob);
                        ob->set_temp("job_over",1);
                        ob->delete_temp("start_job");
                  }
                  else
                  {
                 switch( random(2) ) {
                        case 0:
                        message_vision(HIR"������������һ���ɹű�ʿ��\n" NOR,ob); 
                        robber=new(__DIR__"robber1");
                        robber->do_change(this_player());
                        robber->move(room);
                        robber->kill_ob(ob);
                        robber->checking(robber,ob);
            ob->kill_ob(robber);
                        break;
                        case 1:
                        message_vision(HIR"������������һ���ɹŽ��졣\n" NOR,ob); 
                        robber=new(__DIR__"robber2");
                        robber->do_change(this_player());
                        robber->move(room);
                        robber->kill_ob(ob);
                        robber->checking(robber,ob);
            ob->kill_ob(robber);
//                        robber->checking(robber,ob);
                        break;
                        }       
//                        return 1;
                  }
              return;
        }

        if (me->is_fighting()) 
        {
                call_out("checking",1, me, ob);
           return;
        }

            return;
}

/*
int do_kill(string arg)
{
        object who = this_player();
        object me = this_object();
        if (me->is_fighting()) 
        {
                message_vision(CYN"\n���ͣ����ͣ�\n"NOR,who);
                return 1;
        }
        if(!arg || present(arg,environment(me))!=me) return 0;
        me->kill_ob(who);
        call_out("checking",1,me,who);
        return 1;
} 

*/

