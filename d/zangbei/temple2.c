 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "������");
        set("long", @LONG
�����½ṹ���أ�����ׯ�أ����ֱܷ��аס��ơ��졢�����������ڳ��Ƴ�
ҹ��Ϣ���ķ�����Χ���������͸�������ֻ�����������������Ż��̴�ʼ��
Ѧ�Ȱ��Ǵ�������Ҳ�ר������ഫ�ĳɹ������ʱ�����ġ��������ס���Ҳ
�������̫�ɵ�Ե�ʣ��������ϡ�٣������Ѿ���Ϊ���䡣
LONG
        );
        set("exits", ([ 
                "northup" : __DIR__"mount2",
                "south" : "/d/xizang/grassland4",	
                
        ]));
        set("item_desc", ([
                "red tower":    "һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
                "yellow tower": "һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
                "white tower":  "һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
                "����":         "һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
                "����":         "һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
                "����":         "һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/monk2":     1,
                __DIR__"obj/statue2":   1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init(){
        add_action("do_look","look");
} 
int do_look(string arg) {
        object me=this_player();
        object item;
   
        if (arg== "hole" || arg == "ǳѨ") {
                if (!me->query_temp("zangbei/������ש��")) 
                        return notify_fail("��Ҫ��ʲô��\n");
                tell_object(me,"�ײ�������ֽ�ȥ������һ���õ�һ��ӲӲ�Ķ�����\n");
                item = new(__DIR__"obj/item");
                item->move(me);
                return 1;
        }
        if (arg == "green tower" || arg == "����") {
                tell_object(this_player(),"һ��ש�������������ɱ��顢���غ��֡���װ����ʽ��������ɡ�\n",);
                if (!me->query("zangbei/������ʩ��"))                   
                        return 1;
                tell_object(me,"��ϸ��ȥ��������������˵��������שʯ�Ѿ��ǳ���ɢ�����ط��������˼��飬
¶������ǳѨ������壩��\n");
                me->set_temp("zangbei/������ש��",1);
                return 1;
        }
        return 0;
}     
