//Cracked by Kafei
// by oyxb
// by acep

#include <ansi.h>
string* xuedao = ({
        "�޹�Ѩ",
        "�ز�Ѩ",
        "�羮Ѩ",
        "�ճ�Ѩ",
        "����Ѩ",
        "���Ѩ",
        "����Ѩ",
        "�縮Ѩ",
        "����Ѩ",
        "�յ�Ѩ",
        "ǿ��Ѩ",
        "�ٺ�Ѩ",
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "��׵Ѩ",
        "��βѨ",
        "����Ѩ",
        "�͹�Ѩ",
        "�ٻ�Ѩ",
        "��̨Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�βѨ",
        "������",
        "����Ѩ"
});


int update_condition(object me, int duration)
{
	object ob;
   if( duration < 1 ) return 0;
	if (!living(me)) {
		message("vision", me->name() + "�ƺ���һ����\n", environment(me), me);
	}
		tell_object(me,HIR"��е�"+xuedao[random(sizeof(xuedao))]+"һ�����飬Ѫ����������ʱ�������ã�\n"NOR);
  if( !me->is_busy() )
{ 
		me->start_busy(5);
}
                me->receive_damage("qi", duration*2 );
                me->receive_wound("qi", duration*2);
      me->apply_condition("yyz_damage", duration - 1);
      if( duration < 1 ) return 0;
	return 1;
}
