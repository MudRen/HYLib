 // work.c
//#include "/feature/damage.c" 
inherit ROOM; 
void create()
{
        set("short", "ʯɽ");
        set("long", @LONG
�����ɽ����ǹ�ͺͺ�ģ���ͬ�ڽ�������ɫ������ɽ�ͣ����ɫ��ɽ��ֻ��
����һЩ��С�Ĺ�ľ����ЩСɽ����������ȥ��һ�룬һ·������ɽ·���಻ʱ��
���Ÿղ������ľ���ʯ�ϡ�һ��С·˳��ɽ�����ѵ�����Զ����·�ľ�ͷ��һ����
ɫ��Сʯ�ݣ�ʯ�ݸ����мҼ�ª��ʯ��ʯ��ǰ��һ��ˮ�ף������ǹ���·���˽�
�ʵġ�
LONG
        ); 
    set("resource/water", 1);
    set("liquid/container", "ˮ��");    
    set("exits", ([ /* sizeof() == 1 */
                "southup" : __DIR__"stonemiao",
                "east" : __DIR__"work",
                "west" : __DIR__"stonehouse",
        ]));
    set("resource/water", 1);
    set("liquid/container", "ˮ��");    
    set("outdoors", "guanwai"); 
    set("coor/x",-1240);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
}
/*void init()
{
        add_action("do_fillwater","fill");
}       
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir; 
        if( !arg || arg=="" ) return 0; 
        if( arg=="skin" || arg=="wineskin" || arg == "jiudai") {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "�ɾ���ʳˮ",
                                "remaining": 5,
                                "drunk_apply": 0,
                        ]) );
                        write("���ˮ����װ���˸ɾ���ʳˮ��\n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��\n");
        }
        return 1;
}*/