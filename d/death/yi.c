// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ����˾");
        set("long", @LONG
˾�ڳ����������޲�ͬ����ӡ֮���ǹض�ү�������˼����
���˶��ģ�����ǧ����ɩ�������ն�����������������������
�ܸ����壬�����ǲ���֮ͽ���к���Ŀ��ȫ����ء�����ա�����ڣ�
רա����֮�ˡ�����������ǰ�������£��㲻�ɵ�һ���亹��
LONG
        );
        set("exits", ([
		"northwest" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/guan":1,
        ]) );
	set("coor/x",-1010);
	set("coor/y",-30);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
