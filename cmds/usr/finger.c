// finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if( !arg ) {
		if( (int)me->query("jing") < 50 )
			return notify_fail("��ľ����޷����С�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
//                if( !FINGER_D->query_only_ip())
//			return notify_fail("�������������⣬����ʹ��finger��\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 50);
        me->start_busy(1);
		write( FINGER_D->finger_all() );

	} else {
          if (arg=="hxsd" && !wizardp(me))
	return notify_fail("��ľ����޷����С�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
		if( (int)me->query("jing") < 15 )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 15);
        me->start_busy(1);
		write( FINGER_D->finger_user(arg) );
	}
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : finger [ʹ��������]
 
���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
 
see also : who
HELP
    );
    return 1;
}
 
