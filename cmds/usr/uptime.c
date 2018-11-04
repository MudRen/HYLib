// uptime.c
// From ES2
// Modified by Yu Jue for JY (1998-3-17)

#include <localtime.h>
#include <mudlib.h>
#include <ansi.h>

inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main(int i)
{
	int t, y, mo, d, h, m, s;
	mixed *ltime;
	string time;

	ltime = localtime(time());
	s = ltime[LT_SEC];
	m = ltime[LT_MIN];
	h = ltime[LT_HOUR];
	d = ltime[LT_MDAY];
	mo = ltime[LT_MON]+1;
	y = ltime[LT_YEAR];
	time = "��";
	
	if(intp(i)){
	      write(HIG"�ϴε���ԭ��"+HIW);
	      write(read_file("/log/static/LASTCRASH"));
	}
	
	while (y) {
		time = chinese_number(y%10) + time;
		y /= 10;
	}
	time += chinese_number(mo) + "��";
	time += chinese_number(d) + "��";
	time += chinese_number(h) + "ʱ";
	time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	write(HIG"\n��������ʱ�䣺"+HIW + time + "��\n");

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	write(HIG+"����ִ��ʱ�䣺"+HIW + time + "��\n"NOR);
	
	return 1;
}

int help(object me)
{
	write(
"ָ���ʽ : uptime\n\n"
"���ָ���������" MUD_NAME "�������Ϸ�Ѿ�����ִ���˶�á�\n"
    );
    return 1;
}
