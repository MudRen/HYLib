// /d/zhuojun/yanzixiang.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "��֬��");
	set("long", @LONG
������ǳ�ɳ����������֬���ˣ�С������վ�Ų���������Ц�ĸ�
Ů���������Ŀ��˲�ͣ�ذ����ﲨ�����������֬��������һ�Ҽ�Ժ��
�����޸�¥��
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"west" :__DIR__"yanfulou",
                "east"  :__DIR__"guangchang",
	]));
	set("objects",([
	__DIR__"npc/zuihan":1,
	]));
       setup();
	replace_program(ROOM);
}	
