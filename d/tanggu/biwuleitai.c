
#include <ansi.h>

//�ļ�Ŀ¼

inherit ROOM;

void create()
{
        set("short", HIG"������̨"NOR);
        set("long", "�����Ǳ������׵���̨�����������ӭ��Ʈ���̨���ܼ�����Χ�۵���Ⱥ����
ߺ�������ģ�����Ц���ģ����������ĵ����ˡ���̨һ�ǹ���һ�����ӣ�paizi����\n");
        set("no_death", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1);
        set("exits", ([ 
			             "out" : __DIR__"kongchangdi",
        ])); 


	set("objects", ([
  //              __DIR__"npc/mu-nianci" : 1,
      	]));

        set("item_desc", ([            
			"paizi" : "\n�����������̨���ƣ���˫����׼����( ok )���Ժ�ʼ���䡣\n",      
        ]));
        setup(); 
}

