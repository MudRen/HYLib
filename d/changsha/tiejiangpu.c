// /d/zhuojun/tiejiangpu.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
�ݽ���������̵�����������ʦŷ���ӵĺ��ˣ������Ƶı�������
���ã������쳣���Բ���֪��������ʿ��ϧ�ؽ�ǧ���������˶�������
������
LONG
	);
set("exits", ([
		"east" :__DIR__"beidajie1",
	]));
        set("objects",([
                __DIR__"npc/tiejiang" : 1,
        ]));

       setup();
	replace_program(ROOM);
}	
