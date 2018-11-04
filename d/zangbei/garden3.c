 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ջ�԰");
        set("long", @LONG
�ջ�԰�ܴ󣬾ջ�԰����÷��԰����ĵ����Ǿޱ����ҩ���軨������������԰��
���еĻ�԰�������˭Ҳ��֪������ռ�˶��ٵأ�ֻ֪��һ���˾��ߵúܿ�Ҳ����
һ����������Ƭ����һȦ����԰��ܾ���û���ˣ�û���������ϲ��Ļ�԰һ����
�����ӵģ�����ֻҪһ�߽�ȥ��ÿ�������ﶼ�������˺�Ȼ���֣�ÿ���˶�����Ҫ
�������
LONG
        );
        set("exits", ([ 
                "northeast" :   __DIR__"garden2",
                "west":         __DIR__"stable",
                "northwest":    __DIR__"sroad1",
        ]));
        set("objects", ([
        ]) );
        set("item_desc", ([
                "�ջ�": "�����＾��԰����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n",
                "flower": "�����＾��Ժ����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n",
        ]));
                
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        add_action("do_pull","pull");
}  
int do_reveal() {
        
        object *inv, *players;
        int i;
        
        message("vision",BLU"\n�紵�ݶ���԰�����ƺ���һ����Ӱ������һ�ξͲ����ˡ�\n\n"NOR,this_object());
        
        inv = all_inventory();
        players = filter_array(inv, (: interactive($1) :));
        for(i=0; i<sizeof(players); i++) {
                if (!players[i]->query_temp("zangbei/ҹ����Ӱ")) 
                        players[i]->set_temp("zangbei/ҹ����Ӱ", 1);
        }
        set("xiaohe",1);
        return 1;
}  
int do_pull(string arg) {
        object me=this_player();
        object xiaohe;
        
        if (arg== "flower" || arg == "�ջ�") {
                tell_object(me,YEL"
�����ȥ���ְ���һ��ջ�������ջ����ǻ�ģ�����һ�Σ�����������
���澹�и�СС�Ķ�Ѩ��"NOR);
                
                if (!me->query_temp("zangbei/ҹ����Ӱ") || !query("xiaohe")) {
                   tell_object(me,WHT"��Ѩ��տյģ�ʲôҲû�С�\n"NOR);
                        return 1;
                }
                message("vision","�ӵص��º�Ȼ������Ϣ��ð��һ��������\n",this_object(),me);
                tell_object(me,BLU"һ�����ź��µ��˴Ӷ�Ѩ��һԾ��������������\n"NOR);
                xiaohe=new(__DIR__"npc/xiaohe");
                xiaohe->move(this_object());
                xiaohe->kill_ob(this_player());
                set("xiaohe",0);
                return 1;
        }
        return notify_fail("�����/��ʲô��\n");
}     
