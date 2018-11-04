// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	if (!query("decay")) {
		set("decay", 1);
		call_out("decay", 280);
	}
}



void decay()
{
	object me = this_object(), ob = environment();
        if (!me || !ob) return;
	switch(add("decay", 1)) {
		case 2:
			set_temp("apply/long", ({ query("long") + "���ǿ��������Ǻ����ʡ�\n" }));
			tell_object(ob, me->name()+"����ɫ��Щ�����ˡ�\n");
			break;
		case 3:
			set_temp("apply/long", ({ query("long") + "��������ɢ����һ�����ŵ�ζ����\n" }));
			tell_object(ob, me->name()+"ɢ����һ�����ŵ�ζ����\n");
			break;
		case 4:
			set_temp("apply/long", ({ query("long") + "������Щ�����ˡ�\n" }));
			tell_object(ob, me->name()+"��Щ�����ˣ������̱ǵ�ζ����\n");
			break;
		default:
			tell_object(ob, me->name()+"�������õ��ˡ�\n");
			destruct(this_object());
			return;
	}
	call_out("decay", 150);
}
