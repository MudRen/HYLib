 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
�������������ӣ�ͥԺ�������续�����ɫ�ĳ�������ɽ�ּ䡢Ȫˮ����
���ֽ���һ�������Ʈ��Ʈɢ��Զ����һ�ô�������Ļһ��չ���������ŵġ����
��֦Ѿ�������Ϸ���һ���ƣ���һ���Ʊ���
LONG
        );
        set("exits", ([ 
                "north":  __DIR__"bridge",
        ]));
        set("objects", ([
                __DIR__"npc/yexiang":   1,
                __DIR__"obj/trunk":     1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
void reset()
{
        object statue,incense;
               
        ::reset();
        statue = present("trunk", this_object());
        if (!statue->is_character())
        if (!present("winepot",statue)) {
                incense=new(__DIR__"obj/winepot");
                incense->move(statue);
        }
}  
void init() {
        add_action("do_get","get");
}   
int do_get(string arg) {
   
        string arg1,arg2;
        int num,gao;
        object ye;
        
        if (!ye=present("yexiang",this_object())) return 0;
        
        if (sscanf(arg,"%s from trunk",arg1)==1) {
                if (arg1=="winepot") gao=1;
                if (sscanf(arg1,"%s %d",arg2,num)==2)
                        if (arg2=="winepot") gao=1;
        }
        
        if (gao) {
                message_vision("$Nһ���ֵ�ס����,��Ц��˵�����Ҿ���ô��ҵ��ˡ���\n",ye);
                return 1;
        }
        
        return 0;
        
        
}  
