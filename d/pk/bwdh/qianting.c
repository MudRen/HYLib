//qianting.c ǰ�� 

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIC"ǰ��"NOR);
        set("long", @LONG
���ܴ󣬲��õļ������ɣ�����������һ�����磬�����ϻ�����һƬ��
�����Ƶ�ɽ�壬ʮ�ֵ��ն񣬿���ȥ��Щ��ɽ�����ֱȻ�ɽ����Щ������
˭Ҳ��֪����������δ�������ǰ��һ�Ѹߴ����̴ľ�Σ������������޲�
���Ŀ��棬����ǽ�Ϲ����������黭��������Щ��������û�б�İ��衣
LONG
        ); 
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));
        set("exits", ([        
        "northeast" : __DIR__"caodi2",
        "northwest" : __DIR__"caodi1",
        "north" : __DIR__"zoulang1",
        "south" :__DIR__"gate",
        ]));
        
        set("no_death",1);set("bwdhpk",1);

        setup();
}
