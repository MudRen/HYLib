// jinchuang.c ��ҩ
inherit ITEM;
void setup()
{}
void init()
{
        if (this_player()==environment())
                add_action("do_eat", "eat");
}
void create()
{
        set_name("��ҩ", ({"jinchuang yao", "yao", "jinchuang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ʿ�ر��Ľ�ҩ��\n");
                set("value", 5000);
        }
        setup();
}
int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
        if ((int)this_player()->query("eff_qi") == 
            (int)this_player()->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
        else {
                this_player()->receive_curing("qi", this_player()->query("max_qi")/5);
                message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player());
                destruct(this_object());
                return 1;
        }
}

