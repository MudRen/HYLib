// /d/zhuojun/yanfulou.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�޸�¥");
	set("long", @LONG
�޸�¥�ǳ�ɳ������һ�Ҽ�Ժ���ϱ����ؼ���Ӧ�о��У���ʩ��
����һ���������ܹ�˵ġ��޸�¥�ﲻʱ��������Ц����
LONG
	);
set("exits", ([
		"east" :__DIR__"yanzixiang",
	]));
		set("objects",([
	  "/d/qianjin/npc/dancer":2,	
	  ]));
       setup();
	replace_program(ROOM);
}	
