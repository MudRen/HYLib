int time_period(int timep,object me);
string  zuji(string str);
int ckiller=4;
#include <ansi.h>
mapping *lquest = ({
        ([      "quest":                "���״�",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���׶���",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�����Ļ�",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ë��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "Ī��",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����ܽ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����Сʦ̫",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����Сʦ̫",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ϼ",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ʦ̫",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����Ϫ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "����ͤ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "��Զ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "�������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "�������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":                "Ī����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ʱ���",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "½�˷�",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��СӨ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ȫ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�Ű���",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ϣ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ҩʦ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��׺�",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����Ӣ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���޼�",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��Ұ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ذ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��Ȼ",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����ţ",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ԫ",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ׯ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����ʹ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ɽ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ʿ",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��־��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��־ƽ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "С��Ů",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ֳ�Ӣ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "Ƥ����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��־��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "Ѫ������",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ʤ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "׿��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ľ���",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ľ���",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���»��",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���ײ�",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�̴�",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���з�",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ˮ�",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "½����",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ɽ��ͷ",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ŷ����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "С��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���ͷ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ܼ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ϲ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������Ů",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "÷��",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ɻ���",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ժ����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ʨ����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��������",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����ʤ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���ŵ���",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ʩ����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����Ⱥ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����ɺ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�߸���",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��ƽ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�͵�ŵ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "Ҷ����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�Ϻ�����",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ʯ����ʿ",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ʹ���ʿ",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�Ʋ���",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "һƷ����ʿ",    "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�Ժ�",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ų���",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ų˷�",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ֲ�",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������̽�ͽ",  "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�����ʦ",      "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��־",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ɨ��ɮ",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ۿ�����",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������ʦ",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���ȴ�ʦ",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���Ʊ���",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������ʦ",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���ޱ���",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��Ϊ����",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�巨����",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "ʷ�Ǵ�",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��Ӣ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���ƽ",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "½��",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ѱ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�߿���",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�˰���",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "֣��",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ؾ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����ʦ̫",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����ʦ̫",        "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�Ǻ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "����",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�Ƹ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "���",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ֻ�",            "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "�ն���",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "��һ��",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
       ([      "quest":                "������",          "exp_bonus":random(25)+30,"pot_bonus": random(12)+10    ]),
        ([      "quest":   "����",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�佫",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�ٱ�",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "��С��",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "���ϰ�",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "Ǯ�ۿ�",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "���",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "��å",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "��åͷ",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "������",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "ƽһָ",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "ҩ�̻��","exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "������",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "������",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "С����",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "̷�Ѽ�",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "��ҩ��",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "ʷ��ɽ",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�η�����","exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "���е�",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�Ҷ�",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�ܼ�",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "��Ա��",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "��ݺݺ",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�⹭Ӱ",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�۷�",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�һ��峤","exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�һ�ͯ",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�к�",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "������",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "��һ��",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "Ǯ����",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "���Ĵ�",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "������",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "������",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����˥",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "֣����",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "ʷ��",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�տն�",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "ΤС��",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "���",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "С���",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "���͹�",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "��ͷ��",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "����ɩ",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "Τ����",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "�깫",    "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "éʮ��",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":   "ŷ����",  "exp_bonus":random(10)+30,"pot_bonus": random(8)+10  ]),
        ([      "quest":                "������", "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�ذ���",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���׳����",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "С��",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�ο�",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�η�����",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���ƹ�",     "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��������",   "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���峬",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "С��å",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��Ʀ",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�ƹ�",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�͵���",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��ͷ��",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��Զɽ",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "̫��",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��������",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�׹���",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "Ǯ�ϱ�",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���Ʋֹ�ʦ",  "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���촨",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "ɣ����",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�����",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "ѦĽ��",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���Ǻ�",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "Ǯ�ཡ",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "½��Ӣ",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��ǧ��",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�仨",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�ر�",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "ɳͨ��",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��ͨ��",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��",       "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�����",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�Ϻ���",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���ϰ�",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�ֺ�",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���ɵ���",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��ص���",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��ǧ��",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "���ҵ���",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "С��",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��ͨ",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "��Ī��",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����ʦ̫",    "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "����",        "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "�ϴ���",      "exp_bonus":random(15)+30,"pot_bonus": random(8)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "ʷ��ͷ",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�°���",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�ϳ���",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���ƹ�",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "С��",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "³����",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��̩��",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����ľ��",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��Ա��",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��ݼ",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��Ϊ��",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�����",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�ﲮ��",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�販ʿ",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���ı�",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�����",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "Ү����",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����ͨ",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��ܽ",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "ľ��",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "ƫ��",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�α�",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����ϰ�",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���˿�",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�����",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����ͨ",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�ƻ�",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",             "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�����",           "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�˷��Ϸ���",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���ٴ�ʦ",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����̩",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������ʿ",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "ʿ��",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��ͷ��",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�̴�",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����˾",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��Ů",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�κ�ҩ",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "Ѧ�ϰ�",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "ʯ��",         "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������ʿ",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��˼��",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������ʿ",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "̫��",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��Ů",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��ũ�����",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����������",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��һ��",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����ʹ��",   "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�ų���",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�ſ�",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��Ѷ",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "ɳ�콭",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "��ʲ��",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "�Ϻ���",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "���˴�",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����ͷ",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "������",     "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
        ([      "quest":                "����",       "exp_bonus":random(20)+30,"pot_bonus": random(10)+10   ]),
});

mixed rooms = ({
        ({
        "���ֹ㳡","����·","������","������Ϊ��","����������",
        "��΢��","����ƺ","��ѩɽɽ��","������","ȫ��̴���", 
        "Ĺ��","�һ�ɽׯ����","��ӹ��","������","���޺�", 
        "ѩɽ��ɽ��","һƷ�ô�Ժ","������ɽ��","�κϾ�","��ָ��", 
        "��ȸ����","��������","�׻�����","��������","�찲��",
        "�������","�����ھ�","�����","������","Ȫ������",
        "��������","�������","����¥","������","��ɽ����",                
        "�߹���","�����ַ�","��������","ϲ�ݳ�","��³��", 
        "����","ɽ����","����ͷ","��ͷɽ���","��ɽ����",
        "����Ժ","ӿȪ��","������","���Ϸ�","�Ͻ��",
        "�ɷ��","����ɽ��","������","����̶","���ɷ�",                
        "��Ӧ��","�����","������Ժ","������","������", 
        "��������","������","�һ�������","�嶾�̴���","������",
        "������","˿��֮·","��ͷɽ���","�ڷ��","���ŷ�",
        "�ϳ�","��Ҥ��","��Ȼ��","��ľ�沿��","��ľ��Ӫ��",
        "�ɹŲ�ԭ","���岿��","СϪ��","��Ҷ�㳡","���������",
        "������","���ݳ�","������","ɽ����","��ݮ��",
        "�����ַ�","ʮ�ֽ�ͷ","����������","�ָ�ʫ��","佻�Ϫ",
        "���Ӿ�¥","��ţ���","������","��گ�»���","������",
        "�����","���ƺ���","³����","ϲ�ݳ�","̫�ͽֿ�",
        "��³��","ʥ��","���ǹ�","��ѩɽ��´","���϶�",
        "������","ʮ����","��ɽ���","Ӣ�ۻ��","������",
        "�����ھ�","�����","��������լ","����ɽ����","��ˮ̶",
        "̫��","�����","������","��������","������",
        "������","ʥ����","�����ô���","����������","ƽ����",
        "���Է�","������","������","��������","������Ժ",
        "��̳��","��ȳ�","Ⱥ�ɹ�","������","ɯ��ƺ",
        "�����","����","�ƺӰ�կ��","������ԭ","���",
        "������ջ","������ջ","��ͩ԰���","����㳡","���ĵ�",
        "��ʦ��","�ɷ��","Ȫ������","��ӹ��","������Ժ",
        "��������","��ɽׯ","����ͤ","�Ͻ���","��ɽ��",
        "��ʶ�","��ڷ�","��ɽɽ��","����̨","�嶼����",
        "���׽���","������","���湬","����������","���칬",
        "�۾�¥","��ظ�ԭ","����ʹ����","����������","��ȸ������",
        "���¶�","��ң��","ѩɽ��ɽ��","ѩɽ��ɽ��","����̨",
        "�κϾ�","����ʮ�ֽ�ͷ","�������","����Ժ","������",
        "����ɽ��","�չ���","����������","ף�ڵ�","������",
        "��翷�ɽ��","������","��ɽ����","����ɽ��","ӭ��Ƶ�",
        "��ָ��","��ָ��","������","Ĵָ��","̫�׾�¥",
        "ʢ������","������","���س�����","���Ṭ","���տ���ɽ",
        "�ϳ���","��ӹ��","����Ͽ","ů��","�ʹ�����",
        "�����","ϲ����","ӭ��¥","����","������",
        "������","��Ĺ�ڲ�","ϲ����","ӭ��¥","���岿��",
        "���س�����","�Ϸʹ㳡","�Ž��㳡","����㳡","���ݶ���",
        "��������","�껨̨","�Ӹ���","�����ͷ","���չ�¥",
        "��������","�˽ǽ�","������������","������","�����ĳ�",
        "��ɳ�㳡","�ϲ��㳡","����ʮ�ֽ�ͷ","�̼���","������",
        }),
        });

mixed names = ({
        ({
        "���ֹ㳡","����·","������","������Ϊ��","����������",
        "��΢��","����ƺ","��ѩɽɽ��","������","ȫ��̴���", 
        "Ĺ��","�һ�ɽׯ����","��ӹ��","������","���޺�", 
        "ѩɽ��ɽ��","һƷ�ô�Ժ","������ɽ��","��ָ��", "�����",
        "��ȸ����","��������","�׻�����","��������","�찲��",
        "�¼�����","�����ھ�","�����","������","Ȫ������",
        "��������","�������","����¥","������","��ɽ����",                
        "�߹���","�����ַ�","��������","ϲ�ݳ�","��³��", 
        "����","ɽ����","����ͷ","��ɽ����","����С��",
        "����Ժ","ӿȪ��","������","���Ϸ�","�Ͻ��",
        "�ɷ��","����ɽ��","������","����̶","���ɷ�",                
        "��Ӧ��","�����","������Ժ","������","������", 
        "��������","������","�����޹�","���","������",
        "������","˿��֮·","�ڷ��","���ŷ�","������",
        "�ϳ�","��Ȼ��","��ľ�沿��","��ľ��Ӫ��","�ڷ��",
        "�ɹŲ�ԭ","���岿��","СϪ��","��Ҷ�㳡","���������",
        "������","���ݳ�","������","��ݮ��","��ɺӱ�",
        "�����ַ�","ʮ�ֽ�ͷ","����������","�ָ�ʫ��","佻�Ϫ",
        "��ţ���","������","��گ�»���","������","����",
        "�����","���ƺ���","³����","ϲ�ݳ�","̫�ͽֿ�",
        "��³��","ʥ��","���ǹ�","��ѩɽ��´","���϶�",
        "������","ʮ����","��ɽ���","Ӣ�ۻ��","������",
        "�����ھ�","�����","��������լ","����ɽ����","��ˮ̶",
        "̫��","�����","������","��������","������",
        "������","ʥ����","�����ô���","����������","ƽ����",
        "������","������","��������","������Ժ","��ͤ",
        "��̳��","��ȳ�","Ⱥ�ɹ�","������","ɯ��ƺ",
        "�����","����","�ƺӰ�կ��","������ԭ","���",
        "������","������ջ","��ͩ԰���","����㳡","���ĵ�",
        "��ʦ��","�ɷ��","Ȫ������","��ӹ��","������Ժ",
        "��������","��ɽׯ","����ͤ","�Ͻ���","��ɽ��",
        "��ʶ�","��ڷ�","��ɽɽ��","����̨","������",
        "���׽���","������","���湬","����������","���칬",
        "�۾�¥","��ظ�ԭ","����ʹ����","����������","��ȸ������",
        "���¶�","��ң��","ѩɽ��ɽ��","ѩɽ��ɽ��","����̨",
        "����Է","����ʮ�ֽ�ͷ","�������","����Ժ","������",
        "����ɽ��","�չ���","ȫ��̴���","ף�ڵ�","������",
        "��翷�ɽ��","������","������ɽ��","ӭ��Ƶ�","�����",
        "��ָ��","��ָ��","������","Ĵָ��","̫�׾�¥",
        "ʢ������","������","���Ṭ","���տ���ɽ","����Ͽ",
        "��ӹ��","����Ͽ","ů��","�ʹ�����","�����",
        "�����","ϲ����","ӭ��¥","����","������",
        "������","��Ĺ�ڲ�","ϲ����","ӭ��¥","���岿��",
        "���س�����","�Ϸʹ㳡","�Ž��㳡","����㳡","���ݶ���",
        "��������","�껨̨","�Ӹ���","�����ͷ","���չ�¥",
        "��������","�˽ǽ�","������������","������","�����ĳ�",
        "��ɳ�㳡","�ϲ��㳡","����ʮ�ֽ�ͷ","�̼���","������",
        }),
        });
void init()
{
        add_action("give_quest", "quest");
}


int give_quest()
{
        object letter,ob,room2;
        mapping quest,item,npc,quests;
        object me;
        int j, combatexp, timep,factor,num;
        string room;
string file;
string *roomlines;
string location,local,fname;
string *dir2;

        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"
        });


        me = this_player();
        combatexp = (int) (me->query("combat_exp"));



        
                if(me->query_temp("jobitem"))
        {
tell_object(me,"\n����ʹЦ��˵�������ȰѸղ������ҵĶ����ҵ����˼Ұ�....��\n");
             return 1;
        }
                if(me->query_temp("roomjob"))
        {
tell_object(me,"\n����ʹЦ��˵�������ȰѴ�̽�������ð�....��\n");
             return 1;
        }



        //if ((int)me->query_condition("roomjob")){message_vision("$N����$nҡ��ҡͷ˵����սӹ���̽����!�Ȼ�����!\n", this_object(), me);return 1;}


        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if(combatexp<10000)
        {
tell_object(me,"\n����ʹЦ��˵��������书������....��\n");
             return 1;

        }


        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
tell_object(me,"����ʹ������һ��˵�����Ҹղ�Ҫ�����������أ�\n");
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                   return 0;
             }
             
        }


        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];

 tag=levels[num];
        if (random(5) == 0 || (me->query("combat_exp") < 2000000 && random(2)==0))
        {
        quest = lquest[random(sizeof(lquest))];
        timep = random(100) + 380;
        time_period(timep, me);
        tell_object(me, "�����͸���" + quest["quest"] + "��������������ˡ�\n" NOR);
        message_vision("$N����$nһ���š�\n",this_object(),me);
        if (ob = present("xin", this_player()))
         {
             message_vision("����ʹ����ǰ�������˻�ȥ��\n",me);
             me->delete_temp("menpaijob");
             destruct(ob);
             letter = new("/quest/menpai/letter");
                letter->set("long", "����һ��д��" +quest["quest"] + 
                                    "���ױ��ź����������songxin <id>���͸����ˡ�\n"); 
                letter->move(me);
        

             letter->move(me);
             quest["quest_type"] = "�����͸�";
             quest["exp_bonus"] = quest["exp_bonus"];
             quest["pot_bonus"] = quest["pot_bonus"];
             quest["score"] = 0;

             me->set("quest", quest);
             me->set("songxin",1);
             me->set("task_time", (int)time() + timep);
             me->set("quest_factor", factor);
             me->set("last_task_time", time());
             return 1;     
         }
         else
         {
            letter = new("/quest/menpai/letter");
                letter->set("long", "����һ��д��" + quest["quest"] + 
                                    "���ױ��ź����������songxin <id>���͸����ˡ�\n"); 
            letter->move(me);
            quest["quest_type"] = "�����͸�";
            quest["exp_bonus"] = quest["exp_bonus"];
            quest["pot_bonus"] = quest["pot_bonus"];
            quest["score"] = 0;

            me->set("quest", quest);
            me->set("songxin",1);
            me->set("task_time", (int)time() + timep);
            me->set("quest_factor", factor);
            me->set("last_task_time", time());
if (me->query_temp("menpaijob") < 0)
me->delete_temp("menpaijob");
me->add_temp("menpaijob",1);
if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"���������ˡ�\n" NOR);

            return 1;
         }
}

        if (random(5) == 0)
        {
     quest = QUESTS_D(tag)->query_quest();
	}
        if (random(5) == 0)
        {
     quest = QUESTS_D(tag)->query_quest();
	}
       else
        if (random(5) == 1)
        {
     quest = QUESTH_D(tag)->query_quest();
	}
       else
        if (random(5) == 2)
        {
     quest = QUESTW_D(tag)->query_quest();
	}
       else if (random(15)==0)
{
item  = QUESTW_D(tag)->query_quest();
npc = QUESTS_D(tag)->query_quest();
if (random(2)==1)
npc = QUESTH_D(tag)->query_quest();
 quest = lquest[random(sizeof(lquest))];
             quest["quest_type"] = "�ҵ�"+item["quest"]+"��";
             quest["quest"]=npc["quest"];
             quest["exp_bonus"] = 30;
             quest["pot_bonus"] = 30;
             quest["time"]=800;
             quest["score"] = 10;
            me->set("quest", quest);
            me->set("task_time", (int)time() + 800);
            me->set("quest_factor", 15);
            me->set("last_task_time", time());
me->set_temp("jobitem",item["quest"]);
me->set_temp("jobnpc",npc["quest"]);
me->apply_condition("roomjob",8);
tell_object(me,HIC"����ʹ˵��������Ұѡ�"HIG+item["quest"]+HIC"���ҵ�����������"HIG+npc["quest"]+HIC"����\n" NOR);
if (me->query_temp("menpaijob") < 0)
me->delete_temp("menpaijob");
me->add_temp("menpaijob",1);
if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"���������ˡ�\n" NOR);
if (me->query_temp("menpaijob") > 3 && random(10)==0)
{
me->add("mpgx",1);
tell_object(me,"�����Ĳ���������ɹ��׶�������!\n" NOR);
tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+chinese_number(me->query("mpgx"))+NOR"����\n" NOR);
}
if (me->query_temp("menpaijob") > 3 && random(10)==0)
{
me->add("mpgx",1);
tell_object(me,"�����Ĳ���������ɹ��׶�������!\n" NOR);
tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+chinese_number(me->query("mpgx"))+NOR"����\n" NOR);
}
return 1;
}
else
{
	  //room=rooms[0][random(sizeof(rooms[0]))];
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;

         me->apply_condition("roomjob",10);
	         me->set_temp("roomjob",local);
        quest = lquest[random(sizeof(lquest))];
        //timep = 300+random(300)+10;
        //time_period(timep, me);
             quest["quest_type"] = "��̽";
             quest["quest"]=local;
             quest["exp_bonus"] = 30;
             quest["pot_bonus"] = 30;
             quest["time"]=600;
             quest["score"] = 10;
            me->set("quest", quest);
            me->set("task_time", (int)time() + 600);
            me->set("quest_factor", 15);
            me->set("last_task_time", time());
	  
	  tell_object(me,HIC"����ʹ˵:����˵�ڡ�"HIR+room+HIC"����������һЩ�����¼���"+
           "��Ͽ�ȥ��"HIR+local+HIC"����̽(citan)һ�°ɡ�\n"NOR);
if (wizardp(me))
	  tell_object(me,GRN"WIZ��Ϣ:��̽λ�á�"YEL+fname+GRN"����\n"NOR);

if (me->query_temp("menpaijob") < 0)
me->delete_temp("menpaijob");
me->add_temp("menpaijob",1);
if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"���������ˡ�\n" NOR);
if (me->query_temp("menpaijob") > 3 && random(10)==0)
{
me->add("mpgx",1);
tell_object(me,"�����Ĳ���������ɹ��׶�������!\n" NOR);
tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+chinese_number(me->query("mpgx"))+NOR"����\n" NOR);
}
return 1;
}



        timep = quest["time"];if (!quest["time"]) timep=600;
        timep = timep+360;
        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
             tell_object(me,"�ѡ�"HIR+quest["quest"]+HIC"��ɱ�ˣ����Ա��ɲ�����\n" NOR);
        else
             tell_object(me,"�һء�"HIG+quest["quest"]+HIC"������Ա������á�\n" NOR);
if (me->query_temp("menpaijob") < 0)
me->delete_temp("menpaijob");
me->add_temp("menpaijob",1);
if (me->query_temp("menpaijob") > 1)
tell_object(me,"���Ѿ�����Ϊ�������ˡ�"HIC+chinese_number(me->query_temp("menpaijob"))+NOR"���������ˡ�\n" NOR);

if (me->query_temp("menpaijob") > 3 && random(10)==0)
{
me->add("mpgx",1);
tell_object(me,"�����Ĳ���������ɹ��׶�������!\n" NOR);
tell_object(me,"ĿǰΪֹ,������ɹ��׶�Ϊ��"HIC+chinese_number(me->query("mpgx"))+NOR"����\n" NOR);
}

             quest["time"]=300;
             quest["exp_bonus"]=200+(int)me->query_temp("menpaijob");
             quest["pot_bonus"]=140+me->query_temp("menpaijob")/2;
             quest["score"]=50;
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]+180);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIC "����ʹ˵�����������" + time + "��");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;
        object ob1;
        if (ob->query("money_id"))
        {
        	
             if(!who->query("quest") && !who->query_temp("jobitem") && !who->query_temp("roomjob"))
             {
                  tell_object(who,"û�ҵ��������������������ĵ��Ӱ�æ���ˣ�\n");
                   return 1;
             }
       if ( ob->value() < 2000)
             {
tell_object(who,"����ʹ���˿�$P��������Ǯ˵����̫���ˣ���ô����Ҳ����˼�ó��֣�\n");
                   return 1;
             }
             else
             {

tell_object(who,"����ʹ˵�����ðɣ���ξ����ˣ��²�Ϊ����\n");
                   who->apply_condition("menpai_busy",8+random(8));who->delete_temp("menpaijob");
                   who->delete_temp("menpaijob");
                   who->set("quest",0);
                   who->delete("songxin");
                   who->set_temp("menpaijob",0);
                who->delete_temp("jobitem");
                who->delete_temp("roomjob");
         return 1;
        }
        }
        if(!(quest = who->query("quest")))
        {
             tell_object(who,"����ʹ˵�������㶺�ˣ���Ҫ�Ĳ��������\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
        tell_object(who,"����ʹ��ð���ɣ�����ʲô������Ŀ����ѽ�����������Ϸ��ˣ�\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"����ʹ˵�����Բ���ʱ����ˣ���ĵ��Ӹհѻ�������ˣ�\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"����ʹ���˵�˵����̫���ˣ��Ҿ���Ҫ����������б��£�\n");
             exp = 50 + random(100)+(int)who->query_temp("menpaijob")/2;
             pot = 20 + random(30)+(int)who->query_temp("menpaijob")/3;
             score = 12 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"��ϲ�������һ������\n"NOR);
             tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬\n"+ chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(score)+"�㽭��������\n"NOR);
             who->set("quest", 0 );
             return 1;
}
        return 1;
}

        
        
string ask_jianxi()
{     object guo,ob;
      object *team;
	  int i=0,count=0,minexp,maxexp;
int ckiller;
      string where;
	  guo =this_object();
	  ob=this_player();
	  if ((int)ob->query_temp("menpaijob")<2)
	  return "���������м�����������(quest)�����������˵�ɡ�";
	  	
	  destruct(present("mi jian",ob));if (ob->query_condition("mjb2_busy")) return "��û���յ��κ���Ϣ��";
	  
      //too low exp


      if(ob->query("combat_exp")<1500000)
      return  "��Ĺ���̫���ˡ���Ҫ��Ѱ��·!";//too low exp
      team=ob->query_team();
      count=sizeof(team);
	 // write("\n"+sprintf("%d",count));
	  if(count<=1 && !wizardp(ob))
      return "����һ����?"; //too few people
      if(count>=5 && !wizardp(ob))
	  return "���²������"; //too many people
	  minexp=ob->query("combat_exp");
	  maxexp=minexp;destruct(present("mi jian",ob));if (ob->query_condition("mjb2_busy")) return "��û���յ��κ���Ϣ��";
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  team[i]->apply_condition("mjb2_busy",38);
	  }
	  }
	  if ((maxexp-minexp)>3000000)
      return "���ǵ��书���̫���⡣";//exp too far

	  where=names[0][random(sizeof(names[0]))];
	  guo->apply_condition("mjb_busy",30);
	  ob->set_temp("team_count",count);ob->set_temp("tjob",where);
	  ob->apply_condition("mjb_busy",60);
	  ob->apply_condition("mjb2_busy",38);
	  for(i=0;i<count;i++)
	  team[i]->apply_condition("mjb_busy",60);
ckiller=4;
	  for(i=100;i*i*i/10<=maxexp;i++);
         ob->apply_condition("mptjob",23);
ob->delete_temp("menpaijob");
	  return    "�Ҹյõ���Ϣ����һ����ɵ������������ԡ��ɼ�ϸ͵ȥ�����ɵĻ�Ҫ�ļ�\n"+
		        "���ǸϿ�ȥ"+where+"�����أ�������ȫ�����������ļ���͵�����(xiaohui)��\n"+
			    "�϶����в��ٱ��ɵ��ӽ�Ӧ�������С�ġ�"; 
}

void unconcious()
{
	this_object()->reincarnate();
	this_object()->set("eff_qi", this_object()->query("max_qi"));
	this_object()->set("qi", this_object()->query("max_qi"));
	this_object()->set("eff_jing", this_object()->query("max_jing"));
	this_object()->set("jing", this_object()->query("max_jing"));
	this_object()->set("jingli", this_object()->query("eff_jingli"));
	this_object()->say( "����ʹ��Ц��˵�������޵в����棡\n");
	this_object()->command("hehe");
}

void die()
{
	this_object()->unconcious();
}        


string ask_gift()
{     object who,ob,me;
      object *team;
	  int i=0,count=0,minexp,maxexp,a,exp,pot;
int ckiller;
      string where;
string file;
string *roomlines;
string location;
    string *ob_list = ({
                "/clone/family/jinkuai",
                "/clone/family/jintiao",
                "/clone/family/xiaoyuanbao",
                "/clone/family/dayuanbao",
                "/clone/family/jinding",
        });
	  who =this_player();
	  me=this_object();


if ((int)who->query("mpgx") < 10)
	  return    "������ɹ��׶Ȳ��������ڹ��׶�Ϊ:"+chinese_number(who->query("mpgx"))+"��"; 	  


a=FAMILY_D->query_family_fame(who->query("family/family_name"));

if (a> 10) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
	who->add("combat_exp",exp);
	who->add("potential",pot);
       message_vision("$n��$N΢΢һЦ�������ɵò�������ָ��������书�ɡ�\n",
                       who, me);
        tell_object(who, who->query("family/family_name")+"�ڽ����ϵ�������" + chinese_number(a) + "��\n" NOR);
        tell_object(who,  "��ľ���������" + chinese_number(exp) + "��Ǳ��������"+chinese_number(pot) +
                         "��\n" NOR);

}
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽��������и��࿪֧Ӧ�꣬������Щ���ӣ������ȥ�ɡ�\n",
                       who, me);

                ob = new(ob_list[random(sizeof(ob_list))]);
        who->add("mpgx",-10);
        ob->move(who,1);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
                ob = new("/clone/money/gold");
        ob->set_amount(10+random(20));
        ob->move(who,1);





if (random(6)==0)
{
file = read_file("/clone/medicine/ycgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽��������и���Σ�գ�������Щ��ҩ�������ȥ�ɡ�\n",
                       who, me);
           ob = new(location);
if (ob)
{
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}
}

if (random(8)==0)
{
	file = read_file("/clone/medicine/wgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ�ø���װ����������Щװ���������ȥ�ɡ�\n",
                       who, me);
           ob = new(location);
if (ob)
{
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}
}

if (random(10)==0)
{
        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ����߽�������Ҫ������������������Щ�������ı�ʯ�������ȥ�ɡ�\n",
                       who, me);
           ob = new("/clone/gem/gem");
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}
        who->save();
	  

	  return    "�����ڵ�ʦ�Ź��׶�Ϊ:"+chinese_number(who->query("mpgx"))+"��"; 
}


string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="����ɽ��";

if (str=="binghuodao")  

	output="���𵺵�";

if (str=="city")  

	output="���ݵ�";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="�����ǵ�";

if (str=="city4" || str=="changan")   

	output="�����ǵ�";

if (str=="dali")  

	output="�����";

if (str=="emei")  

	output="��üɽ��";

if (str=="foshan")  

	output="��ɽ��";

if (str=="gaibang")  

	output="ؤ���";

if (str=="gaochang")  

	output="�߲��Թ���";

if (str=="guanwai")  

	output="�����";

if (str=="guiyun")  

	output="����ׯ��";

if (str=="gumu")  

	output="��Ĺ�ɵ�";

if (str=="hangzhou")  

	output="���ݵ�";

if (str=="heimuya")  

	output="��ľ�µ�";

if (str=="hengshan")  

	output="��ɽ��";

if (str=="henshan")  

	output="��ɽ��";

if (str=="huanghe")  

	output="�ƺӾ�����";

if (str=="huashan")  

	output="��ɽ��";

if (str=="jinshe")  

	output="����ɽ����";

if (str=="lingjiu")  

	output="���չ���";

if (str=="lingzhou")  

	output="���ݵ�";

if (str=="meizhuang")  

	output="÷ׯ��";

if (str=="mingjiao")  

	output="���̵�";

if (str=="qingcheng")  

	output="���ɽ��";

if (str=="quanzhen")  

	output="ȫ���ɵ�";

if (str=="quanzhou")  

	output="Ȫ�ݵ�";

if (str=="shaolin")  

	output="�����µ�";

if (str=="shenlong")  

	output="��������";

if (str=="songshan")  

	output="��ɽ��";

if (str=="suzhou")  

	output="���ݵ�";

if (str=="taishan")  

	output="̩ɽ��";

if (str=="taohua")  

	output="�һ�����";

if (str=="tianlongsi")  

	output="�����µ�";

if (str=="wanjiegu")  

	output="��ٹȵ�";

if (str=="wudang")  

	output="�䵱ɽ��";

if (str=="xiakedao")  

	output="���͵���";

if (str=="xiangyang")  

	output="�����ǵ�";

if (str=="xiaoyao")  

	output="��ң�ֵ�";

if (str=="xingxiu")  

	output="���޺���";

if (str=="xueshan")  

	output="ѩɽ�µ�";

if (str=="xuedao")  

	output="��ѩɽ��";

if (str=="mr")  

	output="Ľ�����ҵ�";

if (str=="kunlun")  

	output="����ɽ��";

if (str=="tiezhang")  

	output="�����ŵ�";

if (str=="huizhu")  

	output="���岿���";

if (str=="yinju")  

	output="һ�ƴ�ʦ�ӵ�";

if (str=="menggu")  

	output="�ɹŲ�ԭ��";

if (str=="qianjin")  

	output="����ǧ��¥��";

if (str=="lingshedao")  

	output="���ߵ���";

if (str=="ruzhou")  

	output="���ݳǵ�";

if (str=="kunming")  

	output="������";

if (str=="jingzhou")  

	output="���ݵ�";

if (str=="yanjing")  

	output="�ྩ��";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="���ݵ�";

if (str=="jyguan")  

	output="�����Ա������ص�";

if (str=="changcheng")  

	output="�����Ա����ǵ�";

if (str=="fairyland")  

	output="���صĺ�÷ɽׯ";

if (str=="sdxl")  

	output="��ħ�������Ĺ";

if (str=="jqg")  

	output="�����";

if (str=="nio")  

	output="ţ�Ҵ��";

if (str=="feihu")  

	output="�������ص�";

if (str=="wuguan")  

	output="������ݵ�";

if (str=="village")  

	output="��ɽ���";

if (str=="taohuacun")  

	output="�һ����";

if (str=="pingan")  

	output="ƽ���ǵ�";

if (str=="lingxiao")  

	output="�����ǵ�";

if (str=="wudujiao")  

	output="�嶾�̵�";

if (str=="hj")  

	output="��ɽ����ԭ��";
if (str=="dali/yuxu")  

	output="��������۵�";
if (str=="dali/wuliang")  

	output="��������ɽ��";
if (str=="huanghe/yyd")  

	output="�ƺ�������";
if (str=="kaifeng")  

	output="����ǵ�";
if (str=="feitian")  

	output="������������";
if (str=="japan")  

	output="�ձ��񻧵�";
if (str=="tangmen")  

	output="���ŵ�";
if (str=="luoyang")  

	output="�����ǵ�";

if (str=="chengdu" || str=="city3")  

	output="�ɶ���";

if (str=="baihuagu")  

	output="�ٻ��ȵ�";

if (str=="heizhao")  

	output="�ٻ��ȡ����ӵ�";

if (str=="jiaxing")  

	output="���˵�";

if (str=="shiliang")  

	output="�¼�ׯ��";

if (str=="wuyi")  

	output="����ɽ����";

if (str=="yanping")  

	output="��ƽ�ǵ�";
	

if (str=="jiangling")  
{
	output="����ǵ�";
}

if (str=="yueyang")  
{
	output="�����ǵ�";	
}

if (str=="qilian")  
{
	output="����ɽ��";	
}

if (str=="shouxihu")  
{
	output="��������";	
}

if (str=="wuxi")  
{
	output="�����ǵ�";	
}

if (str=="yixing")  
{
	output="���˳ǵ�";	
}
if (str=="taiwan")  
{
	output="̨�������";	
}
if (str=="nanyang")  
{
	output="����������";	
}
if (str=="nanshaolin")  
{
	output="�����ֵ�����";	
}

if (str=="cangzhou")  
{
	output="���ݵ�����";	
}

if (str=="tanggu")  
{
	output="�����ǵ�����";	
}

if (str=="yunhe")  
{
	output="�������˺ӵ�";	
}

if (str=="hainan")  
{
	output="���ϵ���";	
}

if (str=="jindezheng")  
{
	output="�������";	
}

if (str=="yandang")  
{
	output="�㵴ɽ��";	
}

if (str=="jinling")  
{
	output="����ǵ�";	
}

if (str=="sandboy")  
{
	output="����ũ���";	
}

if (str=="huangshan")  
{
	output="��ɽ��";	
}

if (str=="yubifeng")  
{
	output="��ʷ��";	
}

if (str=="quanzhouchen")  
{
	output="Ȫ�ݳ��ڵ�";	
}

if (str=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="���� ����ɽ��";	
}

if (str=="annan")  
{
	output="���ϸ�����";	
}

if (str=="taiyuan")  
{
	output="̫ԭ������";	
}

if (str=="hefei")  
{
	output="�Ϸʸ�����";	
}

if (str=="jiujiang")  
{
	output="�Ž�������";	
}

if (str=="baling")  
{
	output="���긽����";	
}

if (str=="xinjiang")  
{
	output="�½�������";	
}
if (str=="dingxiang")  
{
	output="���帽����";	
}
if (str=="suiye")  
{
	output="��Ҷ������";	
}


if (str=="mayi")  
{
	output="���ر߽�������";	
}
if (str=="xuzhou")  
{
	output="���ݳǸ�����";	
}
if (str=="jinan")  
{
	output="���ϳǸ�����";	
}
if (str=="guizhou")  
{
	output="�����Ǹ�����";	
}

if (str=="nanchang")  
{
	output="�ϲ��Ǹ�����";	
}


if (str=="changsha")  
{
	output="��ɳ�Ǹ�����";	
}


if (str=="zhongzhou")  
{
	output="���ݳǸ�����";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="���ػ�ر�������";	
}

return output;
}