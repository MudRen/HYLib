// /d/yazhang/shuifang.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "˯��");
	set("long", @LONG
������Ȼ����ȴ�ǳ��ĸɾ������Ϸ��ż��Ŵ�������˯�ż�����
�ˣ��㷢�������һ�Ŵ�û����˯����������ߵ����ߣ���ͷ��˯��
LONG
	);
set("exits", ([
                 "north" : __DIR__"kezhanup",   
	]));
       setup();
	replace_program(ROOM);
}	