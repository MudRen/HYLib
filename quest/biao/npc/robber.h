void init()
{
       remove_call_out("leave");
        call_out("leave",10);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "ǿ�����˳�ȥ�������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",15);
}
void destroying(object me)
{
        destruct(me);
        return;
}
int checking(object me, object ob)
{
if(!me)
return 1;
if(!ob)
return 1;

        if((int)me->query("qi")* 100 / (int)me->query("max_qi") <= 10){
                if (!living(me)) return 1;
                 else {
                  message_vision(CYN"\n$N�е����������֣�������\n\n$N�����ݶ��밵�ﲻ���ˡ�\n\n"NOR,me);
                  destruct(this_object());
                  return 1;
                 }
        }

        if (me->is_fighting()) 
        {
                call_out("checking",1, me, ob);
                return 1;
        }

        if ( !present(ob->query("id"), environment()) && present("biao che",environment()) )
           {  
                command("laugh");
                command("jie biao che");
                message_vision("$N�����ڳ���Х��ȥ��\n", me);
                call_out("destroying",1,me);
                return 1;
        }
        if (!present(ob->query("id"), environment()))
          {
              message_vision("$N�㬵�˵���������ܵĿ죡��\n",me);
              command("sigh");
              message_vision("$N���м�������ʧ�ڰ���\n",me);
              call_out("destroying",1,me);
              return 1;
          }
             
}


void die()
{
        object ob, me, corpse;
        
        ob = this_object();
message_vision("$N��ž����һ�����ڵ��ϣ���������˿��Ѫ��ʹ��������˼��¾����ˡ�\n", ob);
        destruct(ob);
        return;
}