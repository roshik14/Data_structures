std::string error_str(size_t pos, size_t N);

template <typename T, size_t N>
array<T, N>::array() {
    _data = new T[N]{};
}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
    if (items.size() > N)
        throw std::invalid_argument("Too many elements");
    _data = new T[N] {};
    size_t index = 0;
    for (T item : items) _data[index++] = item;
}

template <typename T, size_t N>
array<T, N>::array(const array &a) : _data(new T[N]{}) {
    std::copy(a._data, a._data + N, _data);
}

template <typename T, size_t N>
array<T, N>::array(array &&a) : _data(a._data) {
    a._data = nullptr;
}

template <typename T, size_t N>
array<T, N>::~array() {
    delete []_data;
}

template <typename T, size_t N>
array<T, N>& array<T, N>::operator=(array &&a) {
    if (this != &a) {
        delete []_data;
        _data = a._data;
        a._data = nullptr;
    }
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
    if (pos > N) {
        throw std::out_of_range(error_str(pos, N));
    }
    return _data[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
    if (pos > N) {
        throw std::out_of_range(error_str(pos, N));
    }
    return _data[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
    return _data[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](size_type pos) const {
    return _data[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
    return _data[0];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::front() {
    return _data[0];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
    return _data[N-1];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::back() {
    return _data[N-1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() noexcept {
    return _data;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::data() const noexcept {
    return _data;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() noexcept {
    return &_data[0];
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::begin() const noexcept {
    return &_data[0];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() noexcept {
    return N == 0 ? &_data[N] : &_data[N-1];
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::end() const noexcept {
    return N == 0 ? &_data[N] : &_data[N-1];
}


template <typename T, size_t N>
constexpr bool array<T, N>::empty() const noexcept {
    return N == 0;
}

template <typename T, size_t N>
constexpr typename array<T, N>::size_type array<T, N>::size() const noexcept {
    return N;
}

template <typename T, size_t N>
constexpr typename array<T, N>::size_type array<T, N>::max_size() const noexcept {
    return N;
}

template <typename T, size_t N>
void array<T, N>::swap(array &other) noexcept {
    array<T, N> tmp(*this);
    *this = std::move(other);
    other = std::move(tmp);
}

template <typename T, size_t N>
void array<T, N>::fill(const T& value) {
    for (size_t i = 0; i < N; ++i)
        _data[i] = value;
}

std::string error_str(size_t pos, size_t N) {
 return "array::at: __n (which is " + std::to_string(pos) + ") >= _Nm (which is " + std::to_string(N) + ")";
}

