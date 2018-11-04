// drink.c
// by snowman@SJ 02/04/1999.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object obj;
    
    if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");

    if( (int)me->query("water") >= me->max_water_capacity() )
	     return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");
    if (!environment(me)) return notify_fail("Ŀǰ�����⡣\n");
    if (!me) return notify_fail("������ˡ�\n");

    if(!arg){
    	     obj = environment(me);
             if(!obj->query("resource/water"))
                    return notify_fail("��ط���ûˮ��\n");
         
             if((string)obj->query("drink_msg"))
	            message_vision(obj->query("drink_msg"), me);
	     else message_vision("$N����һЩ��ˮ������������ȥ��\n", me);
	     me->add("water", 20);
	     if( obj->query("liquid/drink_func") ) return 1;
	     return 1;
	     }
	
    else if(!objectp(obj = present(arg, me)) )
    	     return notify_fail("������û������������\n");

    if(!obj->query("liquid") )
             return notify_fail("������㣬�ⶫ��װ�кȵ���\n");
    if(!obj->query("liquid/remaining") )
	     return notify_fail( obj->name() + (obj->query("liquid/name") ? "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
			
    me->add("water", 10+((int)obj->query("liquid/drunk_apply")?obj->query("liquid/drunk_apply"):20));
     
    obj->set("value", 0);
    obj->add("liquid/remaining", -1);
    
//    if((int)obj->query("liquid/busy"))
//             me->start_busy(obj->query("liquid/busy"));
    
    if((string)obj->query("drink_msg"))
             message_vision(obj->query("drink_msg"), me, obj);
    else message_vision("$N����$n������غ��˼���" + obj->query("liquid/name")+ "��\n", me, obj);
              
    if( !obj->query("liquid/remaining") ){
    	     if((string)obj->query("finish_msg"))
	           write(obj->query("finish_msg"));
             else write("���Ѿ���" + obj->name() + "���" + obj->query("liquid/name")+ "�ȵ�һ��Ҳ��ʣ�ˡ�\n");
             }

    if( obj->query("liquid/drink_func") ) return 1;
    if (!obj) return 1;

    switch(obj->query("liquid/type")) {
	     case "alcohol": me->apply_condition("drunk",(int)me->query_condition("drunk")+ (int)obj->query("liquid/drunk_apply")); break;
	     case "xx_poison": me->apply_condition("xx_poison",(int)me->query_condition("xx_poison")+ (int)obj->query("liquid/drunk_apply")); break;
	     
	}
    return 1;
}



int help(object me)
{
    write(@HELP
ָ���ʽ : drink [��Ʒ����]
 
���ָ������������ˮ��

����
    drink jiudai.
    
    drink.   ( ��������ڵĵط���ˮԴ�Ļ�)��
     
HELP
    );
    return 1;
}
 
