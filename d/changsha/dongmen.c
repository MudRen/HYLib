// /d/zhuojun/dongmen.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "���ĸ�");
	set("long", @LONG
���ĸ����ǳ�ɳ�ųǵı�־����¥ʼ������������������Ǭ¡
ʱ�ڣ����������ޡ����ն���"������ɽ�����ۣ�����̻��ܹ���"
����Ϊ����֮���ԡ���˵�˴�����¡�������˲�¡�����ס�¥��
���㣬���߷��ܣ�������������ַռ�ų�����ߵ��ƣ���֮������
30���׸ߵĳ�ԫ֮�ϣ�������߷�Ϊ�飬Զ����´ɽΪ��������ͦ
�͡���������Ϊ��ɳ�ųǵı�־��
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"east" :__DIR__"eroad1",
                "west"  :__DIR__"dongdajie1",
	]));
       set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
