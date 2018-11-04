// mg-indoor.c �Թ�����
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "�߲��Թ�" NOR);
        set("long", "ͻȻ֮�䣬��ǰ��Ȼ���ʣ�����һ��Ƭ�յأ���ͷ����������
"HIM"����"NOR"(tiemen)��Ƕ�ڴ�ɽ���С�����������ŷ����������\n");
        set("exits", ([
              "east" : __DIR__"mg3",
              "west" : __DIR__"mg4",           
        ]));        
        set("no_sleep_room", 1);
        set("item_desc",([           
         "tiemen" : "������ϡ�ѿ���һ���죬������͸����һ˿��������Ӧ�ÿ��Դ�(open)����\n", 
	  ]));
        setup(); 
}
void init()
{
        add_action("do_move","open");
}

int do_move(string arg)
{
        object room;
        if( !arg || arg!="tiemen" ) return 0;
        if(!(room = find_object(__DIR__"tianjin")))
        room = load_object(__DIR__"tianjin");
        if(!room->query("exits")){
         message("vision","ͻȻ�������ﴫ��һ��������������ǲ�Ҫ������Ϊ�á�\n", this_object() );
         return 1;
         }       
        message("vision","���ź�Ȼ������������������һ�໺���ƿ���¶��һ�������ĳ��ڡ�\n", this_object() );
        set("exits/northup", __DIR__"tianjin");
        room->set("exits/southdown", __FILE__);
        message("vision", "���ź�Ȼ����������������¶��һ�����ڡ�\n",room );  
        remove_call_out("close_door");
        call_out("close_door", 5);
        return 1;
}

void close_door()
{
        object room;
        if( !query("exits/northup") ) return;
        message("vision","��Ȼһ�������������������ֻ����غ����ˡ�\n", this_object() );
        if( room = load_object(__DIR__"tianjin") ) {
                room->delete("exits/southdown");
                message("vision", "���ź�Ȼ�����������������������ƻ�ԭ������������ס�ˡ�\n", room );
                  }
        delete("exits/northup");
}