 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��̲");
        set("long", @LONG
�߳�������һ���ļ���С�ӣ�����������Ϊ���ɫ�������˳�֮Ϊ�����ӣ���
���������Ĺ������ӣ�Ҳ���Ǵ�˵�е���ӣ����Գ�����Ҳմ����������ÿ������
��������ϵ���ͽ��תɽ������ƽʱ��ֻ�м��������ڽ�ϴ���ѡ��ӵ��ϰ�����
��ѵ����������ʯͷ��һ��С·ͨ��ɽ�����
LONG
        );
        set("exits", ([ 
                "northwest":  __DIR__"zhihuo",
                "north":  "/d/qingzh/kunlun18",	
        ]));
        set("item_desc", ([
                "river":        "ˮ���ļ������ǲ��������������ȥ(wade)��\n",
                "������":       "ˮ���ļ������ǲ��������������ȥ(wade)��\n",
//	          "river":        "ˮ���ļ������ǲ��\n",
//                 "������":       "ˮ���ļ������ǲ��\n",
        ]) );
        set("objects", ([
        
                __DIR__"npc/woman":     1,
                __DIR__"npc/girl":      1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",-1100);
        set("coor/y",130);
        set("coor/z",0);
        setup(); 
}  
