// /d/yazhang/masi.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
��ͻ���۰Դ��ԭ����ս������δ��ͻ��ս�������еļ�Ʒ����
�߽����У��㷢������������ۿ��쳣��ʹ�㶼��Ը���ᡣ
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                  "south" : __DIR__"dongdajie1",  
	]));
 set("objects",([
 __DIR__"npc/horse":2,
 ]));
       setup();
	replace_program(ROOM);
}	
