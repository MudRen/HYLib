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
                "southeast" :           __DIR__"garden1",
                "north" :       __DIR__"groom4",
                "southwest":    __DIR__"garden3",
        ]));
        
        set("item_desc", ([
                "�ջ�": "�����＾��԰����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n",
                "flower": "�����＾��Ժ����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n",
        ]));
        
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        add_action("do_pull","pull");
}  
int do_pull(string arg) {
        object me=this_player();
        object xiaohe;
        
        if (arg== "flower" || arg == "�ջ�") {
           tell_object(me,YEL"
�����ȥ���ְ���һ��ջ����ջ�����һ�Σ�����������\n\n"NOR);
                return 1;
        }
        return notify_fail("�����/��ʲô��\n");
} 
