 inherit ROOM;
void create()
{
    set("short", "������");
        set("long", @LONG
ʯǽΧ�ɵ�Ժ��ܴ󣬻Һ�ɫ��Ժǽ��ƽ��Ժǽ�����ı�֮�ߣ�����һ��ѹ��
�ĸо���Ժ��������˾޴��ʯ�ϣ��в��ٵķ�������æµ�ļӹ�ʯ�ϡ�Ժ������
��һ���ʾ�ƣ�������Ժ�ӵĶ�����һ���޴���ɭ��ʯͷ�������������ǳ�
���Ĵ��š�
LONG
        );
    set("exits", ([ /* sizeof() == 3 */
       "west" : __DIR__"dayu",
    ]));
    set("objects", ([
        __DIR__"npc/yuzu" : 1,
    ]) );
        set("item_desc", ([
            "sign": "�����˵ķ��˱��빤���������룩��ʮ�η��ɳ�ȥ��\n",
            "��ʾ��" : "�����˵ķ��˱��빤���������룩��ʮ�η��ɳ�ȥ��\n",
        ]) ); 
    set("no_magic", 1);
    set("no_fight", 1);
    set("no_spells", 1);
    set("no_fly",1);
    set("outdoors", "jinan");
    set("coor/x",60);
    set("coor/y",1880);
    set("coor/z",0);
        setup();
} 
void init(){
        add_action("do_work", "work");
    if(!wizardp(this_player()) && this_player()->query("marks/���˷绯")){
            "/cmds/std/look"->look_room(this_player(),this_object());
            this_player()->set("startroom", __FILE__);
            add_action("do_quit","quit");
    }
} 
int do_work(){
        object me;
   int i, gin, sen;
        me = this_player();
        i = me->query_temp("jail_work");
        gin = me->query("jing");
        sen = me->query("qi");
        if(me->is_busy()) return notify_fail("��Ķ�����û����ɣ����ܹ�����\n");
        message_vision("$N����Ĺ����۵�Ҫ��\n", me);
        if(me->query("jing") > 1){
                me->add("jing",-(gin/10));
        }
        if(me->query("qi") > 1){
                me->add("qi",-(sen/10));
        }       
        me->start_busy(2);
        me->set_temp("jail_work", i+1);
        return 1;        
} 
int valid_leave(object me, string dir){
        object obj;
        
        if(obj = present("yu zu", this_object())) {
                if(dir == "west" ) {
                        if(me->query("marks/���˷绯") && me->query_temp("jail_work") < 20){
                                return notify_fail("����ȵ�����վס����û�����깤�����ߣ���\n");
                        } else if(me->query_temp("̽��")){
                                me->delete_temp("̽��");
                        } else if(me->query("marks/���˷绯")){
                                me->delete("marks/���˷绯");
                        } 
                        me->delete_temp("jail_work");
                }
                if(dir == "east"){
                        if( me->query("marks/���˷绯")){
                                return notify_fail("����ٺ�Ц��������ô�����������𣿡�\n");
                        } else if(!me->query_temp("̽��")) {
                                return notify_fail("����˵�������η��صأ�����Ī�硣��\n");
                        } 
                }
        }
        return 1;
}
int do_quit(){
        "/cmds/usr/quit"->main(this_player(),"");
        return 1;
}       
