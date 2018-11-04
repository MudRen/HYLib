// open.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{

    if(me->is_busy())
        return notify_fail("��������æ��\n");

/*    if(me->query("combat_exp") < 500000)
{
me->delete_temp("combat_yield");
        return notify_fail("�����ѧ��Ϊ����������!!\n");
}*/
	if( !arg ){
             if(me->query_temp("combat_yield")){
                  me->delete_temp("combat_yield");
                  tell_object(me, "��������ʱ���ַ�����\n");
me->start_busy(1);
                  }
             else{
    if(me->is_fighting()) 
    {
        return notify_fail("���Ѿ��ڴ��ˣ�û�취�پ����򲻻����ˣ�\n");
    }
                  me->set_temp("combat_yield", 1);
                  tell_object(me, "��������ʱ�򲻻��֡�\n");
                  }
             }

        else if( arg == "yes"){ 
    if(me->is_fighting()) 
    {
        return notify_fail("���Ѿ��ڴ��ˣ�û�취�پ����򲻻����ˣ�\n");
    }
                  me->set_temp("combat_yield", 1);
                  tell_object(me, "��������ʱ�򲻻��֡�\n");
                  }
        else if( arg == "no"){
                  me->delete_temp("combat_yield");
me->start_busy(1);
                  tell_object(me, "��������ʱ���ַ�����\n");
                  }

        else return notify_fail("�������ܻ���(yield no)���ǲ�����(yield yes)��\n");

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : yield <yes | no>
 
���ָ���������������ʱ�Ƿ��ַ�����
 
HELP
    );
    return 1;
}
