// Room: binglinfeng.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "���ַ�");
	set("long", @LONG
�����Ǵ�ѩɽ��ߵ�ɽ�壬���긲���ڱ�ѩ֮�У������䡣��������ɽ��
�������µĴ����£��γ��˸�Լ���ɵ�ʮ���ɲ��ȵ�����������ԶԶ��ȥ������
��ѩ�ֺ���ÿ�����죬������ҫ�¾ͻ�÷����������صĹ��Σ���ɫ����ʤ�ա�
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanpo",
	]));
	setup();
}
void init()
{
        mixed *local;
    
        local = localtime(time() * 60);
        if (local[2] < 11 || local[2] > 13) {
	message_vision(HIW
"������ѩ����ͷ�������˹���������$N�������ۡ�ͻȻ��ɽ�±�����һ����ѩ��$N��������������ͷ�ϣ�\n"NOR,this_player());
	message_vision(HIR"$N���²��ȣ�˳��ɽ�µ�����ȥ��\n"NOR,this_player());
	this_player()->unconcious();
	this_player()->move(__DIR__"xuegu");
        }
}