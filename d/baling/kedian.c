// baling/kedian
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������
�ţ��������������������صķ������顣��С����������æ������ת��
�Ӵ�����ǻ�����Ŀ��ˡ��͵�����˴Ӳ�¶�棬��������˭���и��ָ�
���Ĳ²⡣ǽ�Ϲ���һ�����ӡ�
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("exits", ([
		"north" : __DIR__"dongdajie1",
		"up":__DIR__"shuifang",
	]));
set("objects", ([
		__DIR__"npc/xiaoer" : 1
	]));
	setup();
}
int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="up")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("��С����ס���㣺�͹٣�����û��Ǯ��!\n");
		else return notify_fail("�ƹ�����溰�����͹٣���Ǯ��ס�갡!\n");
		return ::valid_leave(me,dir);
		return 1;
}
