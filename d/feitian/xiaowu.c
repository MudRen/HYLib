// /d/feitian/xiaowu
// diabio(����)2001.2.6
inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long",@LONG
��ª���������ܵ�ǽ��ȫ����һЩ���չ޹ޣ������������Ҳ����ڵ��ϻ�
ɢ���Ų���δ���Ʒ��һ������ɫ���������������������������ݽ�
��ɢ�ҵط���һЩ�ճ������þߡ��������һ�����ӣ������һ����ͼ�
�����ӡ�
LONG);
	set("exits", ([
	"south" : __DIR__"xiaodao",

]));
	set("objects", ([
        	__DIR__"npc/biguqing" : 1,
]) );
        set("no_fight",1);
	set("sleep_room",1) ;
	setup();
	replace_program(ROOM);
}
