// "suiye"/houhuayuan
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��԰");
	set("long", @LONG
Ϊ�Ľ���˵�˼��֮�࣬Ԫ˧�������������԰����Ϊ��Ҷһ����
������¥��Ԫ˧�Է��˵�ϲ�����Լ�һ�ߣ��ı߻������࣬��Ψ��ĵ��
��ʤ���ǻ�����Ѱ����¥��֮�࣬�ˡ�Ҧ�ơ���κ�ϡ�������Ʒ��һ��
��ֵ��ǧ���ǻ����������Ŷ��棬��Χ�Ժ�ʯ��֮���仨���絤�̣���
ɫ���ã��⻪��Ŀ��
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"north" :__DIR__"shuaifu",
	]));
 set("objects",([ __DIR__"npc/girl":1,]));
       setup();
	replace_program(ROOM);
}	
