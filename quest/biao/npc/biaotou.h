void destroying(object me)
{
        destruct(me);
        return;
}
int checking(object me, object ob)
{
        if((int)time() > this_object()->query("temp_time"))
        {
                  call_out("destroying",1,me);
                  return 1;
        }
        else
        {
                 call_out("checking",120, me, ob);
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