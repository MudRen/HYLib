// hubo.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	string msg;
	int count,a,exp,pot;
 object obj,maxpot;
    if( me->is_busy() )
	return notify_fail("��Ķ�����û����ɡ�\n");
    if( me->is_fighting() )
        return notify_fail("�������������!��\n");

    if( (int)me->query("jing") < 70 ) return notify_fail("��ľ�������\n");
    if( (int)me->query("qi") < 70 ) return notify_fail("��ľ�������\n");

    if( !me->query_temp("roomjob") ) return notify_fail("��û��������񰡣�\n");

    //if( !me->query_condition("roomjob") ) return notify_fail("����������Ѿ������ˣ�\n");

    if (environment(me)->query("short") !=me->query_temp("roomjob"))
     {
         tell_object(me,HIR"�����ǽ��㵽"+me->query_temp("roomjob")+"ȥ��̽�鱨�İɣ�\n"NOR);
          return 1;
     }


    msg = GRN "$N�븽���Ľ����������һ��˵��һ���"+environment(me)->query("short")+GRN"���﷢�����µ���������˽��ˣ�\n" NOR;

if( !environment(me)->query("no_fight"))
{
if (random(30)==1 && me->query("combat_exp") > 2000000)
//if (me->query("combat_exp") > 2000000)
{
obj=new("/quest/menpaijob/shenlong/menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"Ѳ�߹ٱ�"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIY"��������һ�����׺ݵ�Ѳ�߹ٱ���\n"NOR, obj);
message_vision(HIR"$N˵��: ��������˾��Ҵ�̽�ط�������������������������ˣ�\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
return notify_fail("�Ȱ����ٱ�������˵�ɣ�\n");
}
}
me->apply_condition("roomjob",0);
me->clear_condition("roomjob",0);
me->set_temp("roomjob",0);
me->delete_temp("roomjob");

a=FAMILY_D->query_family_fame(me->query("family/family_name"));
if (a> 10 && random(10)==0) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
	me->add("combat_exp",exp);
	me->add("potential",pot);
        tell_object(me, me->query("family/family_name")+"�ڽ����ϵ�������" + chinese_number(a) + "��\n" NOR);
        tell_object(me,  "��ľ���������" + chinese_number(exp) + "��Ǳ��������"+chinese_number(pot) +
                         "��\n" NOR);

}
exp=30+random(100)+(int)me->query_temp("menpaijob")/2;
pot=30+random(100)+(int)me->query_temp("menpaijob")/3;
        me->add_temp("menpaijob",1);
        me->add("combat_exp",exp);
        me->add("potential",pot);
    message_vision(msg, me);
    msg = GRN "$N�ľ���������" + chinese_number(exp) + "��\n" NOR;
    message_vision(msg, me);
    msg = GRN "$N��Ǳ��������" + chinese_number(pot) + "��\n" NOR;    
    message_vision(msg, me);
    me->set("quest", 0);
    me->start_busy(8);
    me->receive_damage("jing", 50);
    me->receive_damage("qi", 50);
    return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : hubo
 
���ָ����������������У�����̽�鱨�ġ�
 
HELP
    );
    return 1;
}
