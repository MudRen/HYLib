// meat.h

void setup()
{
        set("only_do_effect", 1);
        set("base_weight", 300);
        ::setup();
}

int do_effect(object me)
{
        write("���" + name() + "�������ģ��������ٳ԰ɡ�\n");
        return 1;
}

int broil(object me, object ob)
{
        object fob;

        me = this_player();

	if (me->is_busy())
	{
		write("������æ���أ�������ٿ��ɡ�\n");
		return 1;
	}

        message_vision(HIM "$N" HIM "��" + name() + HIM "����" + ob->name() +
                     HIM "��ϸϸ���ţ�ֻ����ࣱ�ࣼ������ŵ�һ�����˵���ζ"
                     "����ɢ�˳�����$P��״��æ�ѿ��õ�" + name() + HIM "ȡ"
                     "�¡�\n\n" NOR, me);

        fob = new("/clone/food/meat");
        fob->move(me, 1);

        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

	me->start_busy(1);
        return 1;
}
