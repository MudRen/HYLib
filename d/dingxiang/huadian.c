// /d/yazhang/huadian.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
δ��˴������µĻ������������ԡ����и���������������Ŀ����
���������֡����Ͳ��ָߵ͹�����������������Ц����ӭ��
LONG
	);
set("exits", ([
                 "south" : __DIR__"dongdajie2",    
	]));
 set("objects",([
 __DIR__"npc/girl":1,
]));
       setup();
	replace_program(ROOM);
}	
