 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "���ݱ���");
        set("long", @LONG
ˮƽ�羵����ɼ��ˣ�ʢ����з����Щ�ط��ĺ�ˮ�����
���Կ������׵�ʯͷ����ʯ���д����С�㣬ż�����м�����
ð��ˮ�棬���������࣢һ����
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"tulu3",
  "south" : __DIR__"baiyang",
]));
        set("objects", ([
        __DIR__"npc/fish" : 2,
        __DIR__"npc/shrimp" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","�����ĺ�ˮ");
        set("liquid/type", "water");
        set("liquid/container","���ݱ���");
        set("coor/x",-1110);
        set("coor/y",2030);
        set("coor/z",0);
        setup();
} 

void init()
{
        add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir; 
        if( !arg || arg=="" ) return 0; 
        if( arg=="skin" || arg=="wineskin" ) {
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
                                "name": "�����ĺ�ˮ",
                                "remaining": 5,
                                "drunk_apply": 0,
                        ]) );
                        write("�����װ���������ĺ�ˮ��\n");
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
}
     
