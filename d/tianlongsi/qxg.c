inherit ROOM;
void create()
{
        set("short", "���ĸ�");
        set("long",@LONG
����������ɮ�������ľ����ĵط�������ֻ�е�����м������ţ�
���������һ�����ӣ����沢��������֧��ȼ������(candle)������֮
��������ȷȻ�Ǹ��徲֮����
LONG);
        set("exits", ([
		"east": __DIR__"baodian",
        ]));
        set("item_desc",([
                "candle" : "��֧��ȼ�˵ĳ�������Ծ�Ļ����ƺ���ů���������䡣\n",
        ]) );
        set("no_fight",1);
        setup();
}
void init()
{
        add_action("do_shoot", ({"shoot", "she"}));
}

int do_shoot(string arg)
{
        object me = this_player();
        int level, jinglicost;

        level = me->query_skill("finger", 1);
        if (arg == "candle" || arg == "zhu" || arg == "lazhu") {
                jinglicost = 25 + random(10);
                if (me->query("jing") < jinglicost) {
                        write("��̫���ˣ���ЪЪ�ɣ�\n");
                        return 1;
                }
                if (level < 30) {
                        write("�㽫��ָ��׼������ͼ������ָ��������ȥ��ȴ��ôҲ������ָ������\n");
                        return 1;
                }
                me->receive_damage("jing", jinglicost);
                if (level <= 100) {
                        write("��������ָ��һ��ָ���׼������ȥ��");
                        if (level < 40) write("����Ļ���΢΢����һ�Ρ�\n");
                        else if (level < 50) write("����Ļ������һ�Ρ�\n");
                        else if (level < 60) write("����Ļ�����˼��Ρ�\n");
                        else if (level < 70) write("����Ļ���ݺݵػ��˼��β���������\n");
                        else if (level < 80) write("����Ļ��类��ö������ᣬͣ��һ������Ծ������\n");
                        else if (level < 90) write("����Ļ��类��ö������ᣬ���˰��������Ծ������\n");
                        else write("���͡���һ�����죬����Ļ��缸�����ˣ������˼��²���������Ծ������\n");
                        me->improve_skill("finger", me->query("int"));
                        if (!random(5)) message("vision", "$N��������ָָ��㣬��֪����ʲô��\n", me, ({ me }));
                }
                else {
                        write("���ۡ���һ�����������ָ�������ˣ�\n");
                        write("�ڰ������˴�У����ĸ��쵰�ɵģ����������æ�ܹ�ȥ���������µ�ȼ��\n");
                }
                return 1;
        }
        return notify_fail("��Ҫıɱ˭��\n");
}
