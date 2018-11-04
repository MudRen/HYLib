// fill.c
// by snowman@SJ 02/04/1999.

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object obj;
    
    if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");

    if( !arg )
        return notify_fail("�����������ˮ��\n");

    if(!objectp(obj = present(arg, me)) )
    	     return notify_fail("������û������������\n");
    if (!environment(me)) return notify_fail("Ŀǰ�����⡣\n");
    if (!me) return notify_fail("������ˡ�\n");

    
    if(!obj->query("max_liquid"))	
             return notify_fail(obj->name()+"�ⶫ����װ����ˮ��\n");
                  
    if(!environment(me)->query("resource/water"))
             return notify_fail("����û�еط�����װˮ��\n");
             
    if( obj->query("liquid/remaining") )
		message_vision("$N��$n��ʣ�µ�" + obj->query("liquid/name") + "������\n", me, obj);
 
    if((string)environment(me)->query("resource/fill_msg"))
	            message_vision(environment(me)->query("resource/fill_msg"), me, obj);
    else message_vision("$N��$nװ����\n", me, obj);

    obj->set("liquid/type", (string)environment(me)->query("resource/water_type")?environment(me)->query("resource/water_type"):"water");
    obj->set("liquid/name", (string)environment(me)->query("resource/water_name")?environment(me)->query("resource/water_name"):"��ˮ");
    obj->set("liquid/remaining", obj->query("max_liquid"));
    obj->set("liquid/drink_func", 0);
    obj->set("liquid/drunk_apply", (int)environment(me)->query("resource/water_apply")?environment(me)->query("resource/water_apply"):20);
    
    me->start_busy(1);
    return 1;
}



int help(object me)
{
    write(@HELP
ָ���ʽ : fill <��Ʒ����>
 
���ָ��������㽫�յ�����װ��ˮ��
 
HELP
    );
    return 1;
}
 
