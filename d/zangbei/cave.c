 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��Ѩ");
        set("long", @LONG
��Ѩ�ı��ϳ�������̦��ż������Ҷ��϶��͸�µ����ήή�����ز��ҽ��룬
�������һ�ţ�Խ�����ߣ���Խ���ŵ�һ��Ѫ�Ⱥ���ɧζ�����˻����Խ�������
��Ƥ��񡣿��Ըе����������ӲӲ�Ķ�����һ�������ǿеľ���Ķ����ͷ��
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"forest1",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void reset(){
        int i;
        object bear;    
        ::reset();
        
        if (bear=present("bear",this_object()))
        if (!userp(bear) && bear->is_character() && !bear->is_fighting())
                destruct(bear);
                
        i = NATURE_D->get_season();
        
        if(i = 1 || i = 4 ) {
                bear=new(__DIR__"npc/bear_w");
                bear->move(this_object());
        } else {
                bear=new(__DIR__"npc/bear");
                bear->move(this_object());
        }
} 
