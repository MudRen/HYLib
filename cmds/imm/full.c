#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
    int i;
    object obj;

    if( !str || str == "")
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("�������: �Ҳ���"+str+"\n");
    
    tell_object(obj,HIR + this_player()->query("name") + "(" + this_player()->query("id")+ ")Ϊ�������ָ��������״̬��\n"NOR);
    obj = me;
    me->set("eff_qi",obj->query("max_qi"));
    me->set("qi",obj->query("max_qi"));
    me->set("eff_jing",obj->query("max_jing"));
    me->set("jing",obj->query("max_jing"));
    me->set("jingli",obj->query("max_jingli"));
    me->set("neili",obj->query("max_neili")*2);
    me->set("food",obj->max_food_capacity()*2);
    me->set("water",obj->max_water_capacity()*2);

    me->clear_condition();
    write(HIR"�ָ��ɹ���\n"NOR);
    return 1;
}

int help(object obj)
{
  write(@HELP
ָ���ʽ : full

���ô�ָ�����ȫ�ָ������״̬��
HELP
    );
    return 1;
}

