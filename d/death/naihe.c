// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ�����");
        set("long", @LONG
���Ʋҵ�֮��һƬ���������������಻�����˼䣬��˵������
�ڴ�·��������֮�ˣ����ǵظ��а����ؼ������񣬵ظ����ɭ��
�����˼䣬ʮ�˲�����ܾ����¶��ˣ����Դ�·����̫ƽ��������
˳·ǰ�б����ֹ���

LONG
        );
        set("exits", ([
		"south" : "/d/death/naihe2",
		"east" : "/d/death/road3",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-10);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
