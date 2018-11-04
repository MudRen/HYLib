// Room: /city/jianyu.c
#include <ansi.h>
inherit ROOM;
void init();
void create()
{
    set("short", "����");
    set("long", @LONG
������һ�������ļ����������г����һ�ɸ������߸ߵ�����
͸��һ˿���⣬��ֻ�������������µ�������ߴ�����ȥ��
LONG
    );
    set("valid_startroom", 1);
    set("no_fight", 1);
    set("objects", ([
        "/d/city/obj/jitui" : 3,
        "/d/city/obj/jiudai" : 1,
    ]));
    setup();
}
void init()
{
    object ob;
    ob = this_player();
    ob->set("startroom","/d/kaifeng/jianyu");
        remove_call_out("kick_ob");
    call_out("kick_ob",30);
        add_action("do_quit","quit");
       add_action("do_quit","exit");
}
void kick_ob()
{
    object room,*obj;
        int i;
        
        obj=deep_inventory(this_object());
        if (!sizeof(obj))   return;
        for (i=0;i<sizeof(obj);i++){
                if (interactive(obj[i]) && (time()-obj[i]->query_temp("summon_time"))>3000){
                        message_vision(HIY+"�ѵ�һ����һ����������ţ�һ�Ű�$N���˳�ȥ����������׳԰׺ȣ�û�ţ�\n"+NOR,obj[i]);
                if (!room=find_object("/d/jyguan/guangchang") )
                                room=load_object("/d/jyguan/guangchang");
                        obj[i]->move(room);
                        message("vision",HIY+"һ���һ�����ŵĺ��Ÿ����˳���!\n"+NOR,room,({obj[i]}));
                obj[i]->set("qi",1);
                        tell_object(obj[i],"���۵Ĳ����˹�ȥ��\n...�ɴ໹�ǻ��˺���Щ�����˾Ͳ����ˣ�\n");
            obj[i]->set("startroom","/d/jyguan/guangchang");
                    call_out("kick_ob",30);
                        return;
                }
        }
    call_out("kick_ob",100);
}

object do_check(string arg)
{
    object *obj;
    int i;
    if (!arg)   return 0;
    obj=deep_inventory(this_object());
    if (!sizeof(obj))   return 0;
    for (i=0;i<sizeof(obj);i++)
        if (obj[i]->id(arg) && obj[i]->is_character() && !obj[i]->is_corpse())    return obj[i];
    return 0;
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ﲻ��QUIT��\n");
        return 1;
}
