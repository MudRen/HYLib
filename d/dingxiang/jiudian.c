// /d/yazhang/jiudian.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�Ƶ�");
	set("long", @LONG
�����аڷ���ʮ����Բ�����Ա������˿��ˡ�������С������ѩ��
��ë������д����ţ���һ��������¡�ľ���
LONG
	);
set("exits", ([
                 "west" : __DIR__"nandajie2",  
	]));
	set("objects",([
	 __DIR__"npc/xiaoer":1,
	 ]));
       setup();
	replace_program(ROOM);
}	
