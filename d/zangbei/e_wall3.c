 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��կǽ");
        set("long", @LONG
կǽ���ռ�¥�ĸ�ʽ�����ģ�һ�������㶼�м��ۣ�����ֻ��һ��ǽ�ڣ�����
���Ҳ��¶��ͷ�������������������������կ�����վ��ǽ������������Ӹ���
�£�ʮ�ֵ��֡�կǽ������ï�ܵ�ɭ�֣�կǽ������Կ���һ����Ժ��Ժ�ӵ�����
�м����߷�����ǽ��һ�ѳ��ݹ������¡�
LONG
        );
        set("exits", ([ 
                "northwest":    __DIR__"e_wall2",
        ]));
        set("item_desc", ([
                "ladder": "һ�ѳ��ݴ�կǽ��ͨ���Ժ�����������ȥ��climb down����
�������������������⵽���˹��������»�Դ����\n",
                "����":  "һ�ѳ��ݴ�կǽ��ͨ���Ժ�����������ȥ��climb down����
�������������������⵽���˹��������»�Դ����\n",        
        ]));
        
        set("objects", ([
                __DIR__"npc/archer":    2,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        add_action("do_climb","climb");
}  
int do_climb(string arg) {
        
        object me;
        
        me=this_player();
        if (arg=="down" || arg == "ladder" || arg== "����") {
           if (me->query_temp("zangbei/zaiqiang_1"))
                        return notify_fail("���Ѿ������������ˡ�\n");
                message_vision("$N���ų���С�������������ȥ��\n\n",me);
                call_out("pass_river",4,me);
                me->start_busy(6);
                me->set_temp("zangbei/zaiqiang_1",1);
                return 1;
        }
        tell_object(me,"��Ҫ��ʲô��\n");
        return 1;
}  
int pass_river(object me) {
        object room;
        if (!objectp(me) || me->is_ghost()) return 0;
        room=find_object(__DIR__"village");
        if (!objectp(room)) room=load_object(__DIR__"village");
        tell_object(me,"�����ɵ��µ�Ժ���\n");
        message("vision",me->name()+"������������������\n",room);
        me->move(room);
        me->delete_temp("zangbei/zaiqiang_1");
        return 1;
}   
