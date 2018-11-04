// Room: /d/huashan/cave.c
// Date: Look 99/03/25

inherit ROOM;
void create()
{
        set("short", "�ܶ�");
        set("long",@long
���߽���������ʯ�ں��棬���ж��죬�Ǹ����ݵ�ǧ��֮�ڵĴ󶴣�����
���߾ߺ��ǣ����������ԣ����Ծ��б��С�ɽ���ı��������ͻ��һ���ʯ��
����һ��ƽ̨����ʯ֮�¿���ʮ��������(dazi)��������Ѹ���ʯ�����տ�
ʱ��ֻ��һ���̵ֿ��������Ժ��ƺ�ɽ�����ڴˡ���һ��֮�����������Σ���
��һ�ƣ���˵Ҳ�������ٸ���
long);
        set("exits",([
        "right" : __DIR__"rukou",
]));
        set("item_desc",([
        "dazi" : "\t�������ɣ��޳����������䲻ʤ�����㺦�ˡ��ּ�ʮ��������
���Ը���������С�֣�����Щ�����������������ɳ�֮�����������ܡ���
��ų�����ȵ���������ۡ�\n",
        ]));
        set("indoors", "��ɽ" );
        set("book_count", 1);
        setup();
}

void init()
{
        add_action("do_lingwu", "lingwu");
        add_action("do_ketou", "ketou");
}

int do_lingwu(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

        if( present("sword book", me)) {
        if( me->query_skill("sword" , 1) < 100 && me->query_skill("sword", 1) > 30 ) {
        write("�����ʯ���ϵ�ͼ�����򣬾��ö���Ļ��������������١�\n", me);
        me->improve_skill("sword", (int)me->query("int")*3/2);
        me->receive_damage("jing", 15 + random((int)me->query_skill("sword" , 1) / 4));
        return 1; }         
        }
        if( present("staff book", me)) {
        if( me->query_skill("staff" , 1) < 101 && me->query_skill("staff", 1) > 50) {
        write("�����ʯ���ϵ�ͼ�����򣬾��ö���Ļ����ȷ��������١�\n", me);
        me->improve_skill("staff", (int)me->query("int")*3/2);
        me->receive_damage("jing", 15 + random((int)me->query_skill("staff" , 1) / 4));
        return 1; }
        }
}

int do_ketou(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

        if(!arg || arg =="" || arg !="skeleton")
        return notify_fail("��Ҫ��ʲô��\n");

        if(arg=="skeleton") {
        if( ob->query("book_count") < 1) {
        write("����ڵ��ϣ����ź����ϵĿ�ͷ��\n", me);
        return 1;
        }

        if( me->query_temp("ketou/����", 1) == 30 ) {
        ob=new(__DIR__"obj/staff_book");
        if(!clonep(ob))
        return notify_fail("���۵��ɵ��ڵأ�ʲôҲû�з�����\n");
        ob->move(me);
        message_vision("ͻȻ�Ӻ����е���һ���������\n", me);
        me->delete_temp("ketou/����");
        this_object()->add("book_count", -1);
        return 1;
        }

        write("����ڵ��ϣ����ź����ϵĿ�ͷ��\n", me);
        me->add_temp("ketou/����", 1);
        return 1; 
        }
        
}
