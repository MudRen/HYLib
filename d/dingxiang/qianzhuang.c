// /d/yazhang/qianzhuang.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����Ǯׯ");
	set("long", @LONG
���Ƕ����������ͻ������һ��Ǯׯ������׿��������������Ʊ��
��Ҫ˵�����⣬��������ԭҲ���ԶԶң�Ǯׯ���ſڹ���һ��ܴ�Ľ���
���ƣ����顰����Ǯׯ�������Ĺ�̨������ɨ�øɸɾ�����
LONG
	);
set("exits", ([
                 "east" : __DIR__"beidajie2",  
	]));
	set("objects",([
	 __DIR__"npc/wu":1,
	 ]));
       setup();
	replace_program(ROOM);
}	
